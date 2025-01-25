#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::countVowelPermutation(int n) {
	vector<vector<int>> preList = {{1, 2, 4}, {0,2}, {1, 3}, {2}, {2,3}};
	int mod = 1e9 + 7;

	vector<int> last(5, 1), cur(5, 0);
	for (int i = 1 ; i < n ; ++i) {
		for (int i = 0 ; i < 5 ; ++i) {
			cur[i] = 0;
			for (const auto& p : preList[i]) {
				cur[i] += last[p];
				cur[i] %= mod;
			}
		}
		swap(last, cur);
	}
	int result = 0;
	for (int i = 0 ; i < 5 ; ++i) {
		result += last[i];
		result %= mod;
	}
	return result;

}
