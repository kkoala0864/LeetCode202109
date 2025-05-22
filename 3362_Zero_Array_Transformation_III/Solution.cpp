#include <Solution.h>

int Solution::maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
	vector<int> offset(nums.size() + 1, 0);
	vector<vector<int>> start(nums.size(), vector<int>());

	for (const auto& q : queries) {
		start[q[0]].emplace_back(q[1]);
	}

	priority_queue<int> pq;
	int need = 0;
	int sum = 0;

	for (int i = 0 ; i < nums.size() ; ++i) {
		for (const auto& v : start[i]) {
			pq.emplace(v);
		}
		sum += offset[i];

		if (sum >= nums[i]) continue;
		while (nums[i] > sum && !pq.empty()) {
			int r = pq.top();
			pq.pop();
			if (r < i) continue;
			--offset[r+1];
			++need;
			++sum;
		}
		if (nums[i] > sum) return -1;
	}
	return queries.size() - need;
}
