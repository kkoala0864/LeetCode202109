#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::min;
using std::vector;

void sort(string& s) {
	vector<int> cnt(26, 0);
	for (const auto& c : s) ++cnt[c-'a'];

	s = "";
	for(int i = 0 ; i < 26 ; ++i) {
		if (cnt[i] > 0) s += string(cnt[i], i + 'a');
	}
}

string Solution::orderlyQueue(string s, int k) {
	if (k == 1) {
		string result = s;

		for (int i = 1 ; i < s.size() ; ++i) {
			string tmp;
			tmp += s.substr(i) + s.substr(0, i);
			result = min(result, tmp);
		}
		return result;
	} else {
		sort(s);
		return s;
	}
}

