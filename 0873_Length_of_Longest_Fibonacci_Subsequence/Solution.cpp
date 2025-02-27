#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::max;
using std::cout;
using std::endl;

// 1 2 3 4 5 6 7 8
// m[1] = 1, m[2] = 1
// m[3] = 3
// m[4] = 3
int Solution::lenLongestFibSubseq(vector<int>& arr) {
	vector<vector<int>> m(arr.size(), vector<int>(arr.size(), 0));
	unordered_map<int, int> valToIdx;

	int result = 0;
	m[1][0] = 2;
	valToIdx[arr[0]] = 0;
	valToIdx[arr[1]] = 1;

	for (int i = 2 ; i < arr.size() ; ++i) {
		for (int j = i - 1 ; j >= 0 ; --j) {
			m[i][j] = 2;
			int pre = arr[i] - arr[j];
			if (pre < arr[j]) {
				if (valToIdx.count(pre)) {
					m[i][j] = max(m[i][j], m[j][valToIdx[pre]] + 1);
				}
				result = max(result, m[i][j]);
			}
		}
		valToIdx[arr[i]] = i;
	}
	return result == 2 ? 0 : result;

}
