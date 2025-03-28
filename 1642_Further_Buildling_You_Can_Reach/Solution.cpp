#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;

int Solution::furthestBuilding(vector<int> &heights, int bricks, int ladders) {
	priority_queue<int> heap;
	for (int i = 1; i < heights.size(); ++i) {
		int d = heights[i] - heights[i - 1];
		if (d <= 0)
			continue;
		heap.emplace(-d);
		if (heap.size() <= ladders)
			continue;
		bricks += heap.top();
		heap.pop();
		if (bricks < 0)
			return i - 1;
	}

	return heights.size() - 1;
}
