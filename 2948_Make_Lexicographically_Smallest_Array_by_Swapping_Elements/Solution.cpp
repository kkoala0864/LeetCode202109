#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <queue>

using std::min;
using std::pair;
using std::priority_queue;
using std::sort;

int find(vector<int> &root, int idx) {
	if (root[idx] == idx)
		return idx;
	return root[idx] = find(root, root[idx]);
}

vector<int> Solution::lexicographicallySmallestArray(vector<int> &nums, int limit) {
	vector<pair<int, int>> list;
	int size = nums.size();

	vector<int> root;
	for (int i = 0; i < size; ++i) {
		root.emplace_back(i);
		list.emplace_back(pair<int, int>(nums[i], i));
	}
	sort(list.begin(), list.end());

	for (int i = 1; i < size; ++i) {
		if ((list[i].first - list[i - 1].first) > limit)
			continue;
		int lr = find(root, list[i].second);
		int rr = find(root, list[i - 1].second);
		if (lr == rr)
			continue;
		root[lr] = root[rr] = min(lr, rr);
	}
	vector<priority_queue<int, vector<int>, std::greater<>>> pqs(size);
	for (int i = 0; i < size; ++i) {
		int r = find(root, list[i].second);
		pqs[r].emplace(list[i].first);
	}

	for (int i = 0; i < size; ++i) {
		int r = find(root, i);
		nums[i] = pqs[r].top();
		pqs[r].pop();
	}
	return nums;
}
