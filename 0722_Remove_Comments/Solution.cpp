#include <Solution.h>
#include <iostream>

vector<string> Solution::removeComments(vector<string>& source) {
	vector<string> result;
	bool bc = false;

	string curline;
	for (const auto& s : source) {
		for (int i = 0 ; i < s.size() ; ++i) {
			if (!bc && s[i] == '/' && i < s.size() - 1) {
				if (s[i+1] == '/') {
					i = s.size() - 1;
					continue;
				} else if (s[i+1] == '*') {
					bc = true;
					++i;
				} else {
					if (!bc) {
						curline.push_back(s[i]);
					}
				}
			} else if (bc && s[i] == '*' && i < s.size() - 1 && s[i+1] == '/') {
				bc = false;
				++i;
			} else {
				if (!bc) {
					curline.push_back(s[i]);
				}
			}
		}
		if (!bc && !curline.empty()) {
			result.emplace_back(curline);
			curline.clear();
		}
	}
	return result;
}
