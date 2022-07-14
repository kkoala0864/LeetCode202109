#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;
using std::pair;

struct cmp {
	bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
		return lhs.first > rhs.first;
	}
};

vector<vector<int>> Solution::kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	vector<int> idx(nums1.size(), 0);

	for (int i = 0 ; i < nums1.size() ; ++i) {
		pq.push({nums1[i] + nums2[0], i});
	}

	vector<vector<int>> result;
	while (k-- && !pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		result.push_back({nums1[cur.second], nums2[idx[cur.second]]});
		++idx[cur.second];
		if (idx[cur.second] < nums2.size()) {
			pq.push({nums1[cur.second] + nums2[idx[cur.second]], cur.second});
		}
	}
	return result;
}
