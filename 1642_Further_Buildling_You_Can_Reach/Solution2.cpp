#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::max;
using std::priority_queue;

int Solution::furthestBuilding2(vector<int> &heights, int bricks, int ladders) {
	priority_queue<int, vector<int>, std::greater<int>> pq;

	int i = 0;
	while (i < heights.size() - 1) {
		int diff = max(0, heights[i + 1] - heights[i]);
		if (pq.size() < ladders) {
			pq.emplace(diff);
		} else {
			if (!pq.empty() && pq.top() < diff) {
				bricks -= pq.top();
				pq.pop();
				pq.emplace(diff);
			} else {
				bricks -= diff;
			}
		}
		if (bricks < 0) {
			break;
		}
		++i;
	}
	return i;
}
