#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

vector<int> Solution::findThePrefixCommonArray(vector<int> &A, vector<int> &B) {

	int size = A.size();
	vector<int> freq(size + 1, 0);
	vector<int> result;
	int cnt = 0;
	for (int i = 0; i < size; ++i) {
		++freq[A[i]];
		if (freq[A[i]] == 2)
			++cnt;
		++freq[B[i]];
		if (freq[B[i]] == 2)
			++cnt;
		result.emplace_back(cnt);
	}
	return result;
}
