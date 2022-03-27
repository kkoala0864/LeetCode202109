#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;
using std::pair;

vector<int> Solution::kWeakestRows(vector<vector<int>>& mat, int k) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> minHeap;

	for (int i = 0; i < mat.size() ; ++i) {
		int cnt = 0;
		for (const auto& iter : mat[i]) cnt += iter;
		minHeap.push(pair<int, int>(cnt, i));
	}
	vector<int> result;
	while (k-- > 0) {
		result.emplace_back(minHeap.top().second);
		minHeap.pop();
	}
	return result;
}

/*
vector<int> Solution::kWeakestRows(vector<vector<int>>& mat, int k) {
	vector<vector<int>> cnt(mat[0].size()+1, vector<int>());
	for (int i = 0 ; i < mat.size() ; ++i) {
		int local = 0;
		for (const auto& iter : mat[i]) {
			local += iter;
		}
		cnt[local].emplace_back(i);
	}

	vector<int> result;
	int idx = 0;
	while (idx < cnt.size() && k > 0) {
		for (int i = 0 ; i < cnt[idx].size() && k-- > 0 ; ++i) {
			result.emplace_back(cnt[idx][i]);
		}
		++idx;
	}
	return result;
}*/
