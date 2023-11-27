#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int Solution::knightDialer(int n) {
	vector<vector<int>> step = {{4, 6}, {6, 8}, {7,9}, {4,8}, {9}, {}, {7}};

	vector<int> cur(10, 1);
	vector<int> last;
	int mod = 1e9 + 7;
	for (int i = 2 ; i <= n ; ++i) {
		last = cur;
		cur = vector<int>(10, 0);
		for (int j = 0 ; j < 7 ; ++j) {
			for (const auto& v : step[j]) {
				cur[v] += last[j];
				cur[v] %= mod;
				cur[j] += last[v];
				cur[j] %= mod;
			}
		}
	}

	int result = 0;
	for (int i = 0 ; i < 10 ; ++i) {
		result += cur[i];
		result %= mod;
	}
	return result;
}
