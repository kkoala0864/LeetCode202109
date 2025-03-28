#include <Solution.h>
#include <iostream>
#include <unordered_set>

using std::pair;
using std::unordered_set;

struct hashFunc
{
	int operator()(const pair<int, int> &ele) const {
		return ele.first ^ ele.second;
	}
};

int Solution::countLatticePoints(vector<vector<int>> &circles) {
	unordered_set<pair<int, int>, hashFunc> uSet;

	for (const auto &iter : circles) {
		int x = iter[0], y = iter[1], r = iter[2];
		int rSq = r * r;
		for (int i = -r; i <= r; ++i) {
			for (int j = -r; j <= r; ++j) {
				if ((i * i) + (j * j) <= rSq) {
					uSet.emplace(pair<int, int>(x + i, y + j));
				}
			}
		}
	}
	return uSet.size();
}
