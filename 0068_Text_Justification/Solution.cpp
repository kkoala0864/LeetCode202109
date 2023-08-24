#include <Solution.h>
#include <iostream>

void concateStr(int curSize, vector<string>& cur_line, int maxWidth, string& ret) {
	if (cur_line.size() == 1) {
		ret = cur_line.back() + string(maxWidth - cur_line.back().size(), ' ');
	} else {
		int emptySize = maxWidth - curSize;
		int mod = emptySize % (cur_line.size() - 1);
		int space = emptySize / (cur_line.size() - 1);
		int scnt = cur_line.size() - 1;
		for (const auto& cl : cur_line) {
			ret += cl;
			if (scnt-- > 0) {
				ret += string(space, ' ');
				if (mod-- > 0) {
					ret.push_back(' ');
				}
			}
		}
	}
}

vector<string> Solution::fullJustify(vector<string>& words, int maxWidth) {
	vector<string> result;

	int curSize = 0;
	vector<string> cur_line;
	for (const auto& w : words) {
		if (curSize + w.size() + cur_line.size() > maxWidth) {
			string str;
			concateStr(curSize, cur_line, maxWidth, str);
			result.emplace_back(str);
			curSize = 0;
			cur_line.clear();
		}
		curSize += w.size();
		cur_line.emplace_back(w);
	}
	if (curSize > 0) {
		string str;
		for (const auto& cl : cur_line) {
			str += cl + ' ';
		}
		str.pop_back();
		str += string(maxWidth - str.size(), ' ');
		result.emplace_back(str);
	}
	return result;
}
