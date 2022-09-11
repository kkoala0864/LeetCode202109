#include <Solution.h>
#include <iostream>
#include <queue>
#include <unordered_map>

using std::queue;
using std::pair;
using std::unordered_map;
using std::min;

bool Solution::canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
	unordered_map<int, unordered_map<int, bool>> check;
	queue<pair<int, int>> que;

	que.emplace(pair<int, int>(0, 0));
	check[0][0] = true;

	while (!que.empty()) {
		int j1 = que.front().first;
		int j2 = que.front().second;
		que.pop();

		if (j1 == targetCapacity || j2 == targetCapacity || (j1 + j2) == targetCapacity) return true;
		// j1 full
		if (!check[jug1Capacity][j2]) {
			check[jug1Capacity][j2] = true;
			que.emplace(pair<int, int>(jug1Capacity, j2));
		}
		// j2 full
		if (!check[j1][jug2Capacity]) {
			check[j1][jug2Capacity] = true;
			que.emplace(pair<int, int>(j1, jug2Capacity));
		}

		if (!check[j1][0]) {
			check[j1][0] = true;
			que.emplace(pair<int, int>(j1, 0));
		}

		if (!check[0][j2]) {
			check[0][j2] = true;
			que.emplace(pair<int, int>(0, j2));
		}

		int min1 = min(j1, jug2Capacity - j2);
		if (!check[j1 - min1][j2 + min1]) {
			check[j1-min1][j2+min1] = true;
			que.emplace(pair<int, int>(j1-min1, j2+min1));
		}

		int min2 = min(jug1Capacity - j1, j2);
		if (!check[j1+min2][j2 - min2]) {
			check[j1+min2][j2-min2] = true;
			que.emplace(pair<int, int>(j1+min2, j2-min2));
		}
	}
	return false;
}
