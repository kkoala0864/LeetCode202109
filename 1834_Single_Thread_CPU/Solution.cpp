#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::priority_queue;
using std::pair;
using std::max;
using std::greater;

vector<int> Solution::getOrder(vector<vector<int>>& tasks) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	vector<pair<int, int>> al;
	int size = tasks.size();
	for (int i = 0 ; i < size ; ++i) {
		al.emplace_back(pair<int, int>(tasks[i][0], i));
	}
	sort(al.begin(), al.end());

	long cur = 0;
	int aIdx = 0;
	vector<int> result;

	int prev = aIdx;
	while (aIdx < size && (al[prev].first == al[aIdx].first)) {
		pq.emplace(pair<int, int>(tasks[al[aIdx].second][1], al[aIdx].second));
		prev = aIdx;
		++aIdx;
	}

	while (!pq.empty()) {
		int tIdx = pq.top().second;
		long costT = pq.top().first;
		pq.pop();
		cur = max(cur + costT, tasks[tIdx][0] + costT);
		result.emplace_back(tIdx);

		while (aIdx < size && (al[aIdx].first <= cur || pq.empty())) {
			prev = aIdx;
			while (aIdx < size && (al[prev].first == al[aIdx].first)) {
				pq.emplace(pair<int, int>(tasks[al[aIdx].second][1], al[aIdx].second));
				prev = aIdx;
				++aIdx;
			}
		}
	}
	return result;

}
