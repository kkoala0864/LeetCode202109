#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;
using std::min;

int Solution::maxValueOfCoins(vector<vector<int>> &piles, int k) {
	for (auto &p : piles) {
		for (int i = 1; i < p.size(); ++i) {
			p[i] += p[i - 1];
		}
	}
	int size = piles.size();
	int result = 0;

	vector<int> last(k + 1, 0), cur(k + 1, 0);
	for (int i = 1; i <= min(k, (int)piles[0].size()); ++i) {
		last[i] = piles[0][i - 1];
	}

	for (int pi = 1; pi < size; ++pi) {
		for (int i = 1; i <= k; ++i) {
			for (int cn = 0; cn <= min((int)piles[pi].size(), i); ++cn) {
				if (cn == 0) {
					cur[i] = max(cur[i], last[i]);
				} else {
					cur[i] = max(cur[i], last[i - cn] + piles[pi][cn - 1]);
				}
			}
		}
		swap(last, cur);
	}
	return last[k];
}
