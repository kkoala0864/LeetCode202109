#include <Solution.h>
#include <iostream>
#include <vector>

int Solution::countSubstrings(string s) {
	string t(1, '#');
	for (const auto& c : s) {
		t.push_back(c);
		t.push_back('#');
	}
	int size = t.size();
	vector<int> p(size, 0);

	int result = 0;
	int mr = -1;
	int ctr = -1;

	for (int i = 0 ; i < size ; ++i) {
		if (i <= mr) {
			int j = 2 * ctr - i;
			p[i] = min(mr - i, p[j]);
		}
		while (i + p[i] < size && i - p[i] >= 0 && t[i+p[i]] == t[i-p[i]]) {
			++p[i];
		}
		--p[i];
		if (i + p[i] > mr) {
			mr = i + p[i];
			ctr = i;
		}
		result += (p[i] + 1) / 2;
	}

	return result;
}
