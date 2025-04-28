#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int find(vector<int>& root, int idx) {
	if (root[idx] == idx) return idx;
	return root[idx] = find(root, root[idx]);
}

int getStep(int start, int end, int maxDiff, vector<pair<int, int>>& list, unordered_map<int, unordered_map<int, int>>& cache) {
	if (start == end) return 0;
	if ((end - start) < maxDiff) return 1;

	if (cache.count(start) && cache[start].count(end)) return cache[start][end];

	auto cmp_low = [](const pair<int, int>& p, const int& key) {
		return p.first < key;
	};
	auto cmp_upper = [](const int& key, const pair<int, int>& p) {
		return key < p.first;
	};

	int si = lower_bound(list.begin(), list.end(), start, cmp_low) - list.begin();
	int ei = upper_bound(list.begin(), list.end(), end, cmp_upper) - list.begin();

	int idx = upper_bound(list.begin() + si, list.begin() + ei, start + maxDiff, cmp_upper) - list.begin();
	--idx;
	cache[start][end] = 1 + getStep(list[idx].first, end, maxDiff, list, cache);
	return cache[start][end];
}

vector<int> Solution::pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
	auto ori = nums;
	vector<pair<int, int>> list;
	vector<int> root;

	for (int i = 0 ; i < nums.size() ; ++i) {
		root.emplace_back(i);
		list.emplace_back(pair<int, int>(nums[i], i));
	}

	sort(list.begin(), list.end());
	for (int i = 0 ; i < list.size() - 1 ; ++i) {
		int lr = find(root, list[i].second);
		int rr = find(root, list[i+1].second);
		if (lr == rr) continue;
		if (abs(list[i+1].first - list[i].first) > maxDiff) continue;
		root[lr] = root[rr] = min(lr, rr);
	}

	vector<int> result;
	int size = nums.size();
	unordered_map<int, unordered_map<int, int>> cache;
	for (const auto& v : queries) {
		if (v[0] == v[1]) result.emplace_back(0);
		else if (ori[v[0]] == ori[v[1]]) result.emplace_back(1);
		else if (find(root, v[0]) != find(root, v[1])) result.emplace_back(-1);
		else {
			int minV = min(ori[v[0]], ori[v[1]]);
			int maxV = max(ori[v[0]], ori[v[1]]);
			result.emplace_back(getStep(minV, maxV, maxDiff, list, cache));
		}
	}
	return result;
}
