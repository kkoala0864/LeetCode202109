#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

vector<int> Solution::findAnagrams(string s, string p) {
	vector<int> golden(26, -1);

	for (const auto &iter : p) {
		golden[iter - 'a'] = golden[iter - 'a'] == -1 ? 1 : golden[iter - 'a'] + 1;
	}

	vector<int> result;
	vector<int> content = golden;
	int cnt = p.size();
	int start = 0;
	for (int i = 0; i < s.size(); ++i) {
		int idx = s[i] - 'a';
		if (content[idx] == -1) {
			content = golden;
			start = i + 1;
			cnt = p.size();
			continue;
		}

		while (content[idx] == 0) {
			++content[s[start] - 'a'];
			++start;
			++cnt;
		}

		--content[idx];
		--cnt;
		if (cnt == 0)
			result.emplace_back(start);
	}
	return result;
}
