#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::max;
using std::pair;
using std::priority_queue;

int Solution::maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {
	int mod = 1e9 + 7;
	vector<pair<int, int>> list;

	for (int i = 0; i < n; ++i) {
		list.emplace_back(pair<int, int>(efficiency[i], speed[i]));
	}
	sort(list.begin(), list.end(), std::greater<pair<int, int>>());

	priority_queue<int, vector<int>, std::greater<int>> pq;
	long sum = 0, result = 0;
	for (const auto &l : list) {
		int e = l.first;
		int s = l.second;
		pq.emplace(s);
		sum += s;
		if (pq.size() > k) {
			sum -= pq.top();
			pq.pop();
		}
		result = max(result, sum * e);
	}
	return result % mod;
}
