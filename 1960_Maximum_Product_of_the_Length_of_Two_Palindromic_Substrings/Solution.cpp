#include <Solution.h>
#include <iostream>
#include <vector>

vector<int> manacher(const string& s) {
	int size = s.size();
	vector<int> p(size, 0);

	int mr = -1;
	int ctr = -1;
	for (int i = 0 ; i < size ; ++i) {
		if (i <= mr) {
			int j = 2 * ctr - i;
			p[i] = min(mr - i, p[j]);
		}

		while (i + p[i] < size && i - p[i] >= 0 && s[i-p[i]] == s[i+p[i]]) {
			++p[i];
		}
		--p[i];

		if (i + p[i] > mr) {
			mr = i + p[i];
			ctr = i;
		}
	}
	return p;
}

long long Solution::maxProduct(string s) {
	auto p = manacher(s);

	vector<long long> preMax(s.size(), 1);
	vector<long long> postMax(s.size(), 1);

	int size = s.size();
	int j = 0;
	for (int i = 1 ; i < size ; ++i) {
		while (j < i && j + p[j] < i) ++j;
		preMax[i] = max(preMax[i-1], (long long)((i - j) * 2 + 1));
	}

	j = size - 1;
	for (int i = size - 2 ; i >= 0 ; --i) {
		while (j > i && j - p[j] > i) --j;
		postMax[i] = max(postMax[i+1], (long long)((j - i) * 2 + 1));
	}
	long long result = 0;
	for (int i = 0 ; i < size - 1 ; ++i) {
		result = max(result, preMax[i] * postMax[i+1]);
	}
	return result;
}
