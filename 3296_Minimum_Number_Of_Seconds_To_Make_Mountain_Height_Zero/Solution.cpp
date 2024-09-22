#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;
using std::pair;

long long Solution::minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, std::greater<pair<long long, int>>> pq;

	for (int i = 0 ; i < workerTimes.size() ; ++i) {
		pq.emplace(pair<long long, int>(workerTimes[i], i));
	}

	vector<int> idx(workerTimes.size(), 1);

	while (mountainHeight-- > 1) {
		long long t = pq.top().first;
		int i = pq.top().second;
		pq.pop();

		++idx[i];
		pq.emplace(pair<long long, int>(t + (long long)workerTimes[i] * (long long)idx[i], i));
	}
	return pq.top().first;
}
