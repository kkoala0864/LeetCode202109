#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;
using std::pair;
using std::make_pair;
using std::cout;
using std::endl;

vector<int> Solution::kthSmallestPrimeFraction(vector<int>& arr, int k) {
	priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, std::greater<pair<double, pair<int, int>>>> pq;

	for (int i = 1 ; i < arr.size() ; ++i) {
		pq.emplace(make_pair((double)arr[0] / (double)arr[i], make_pair(0, i)));
	}
	vector<int> result = {0, 0};
	while (k-- > 0) {
		double val = pq.top().first;
		int cIdx = pq.top().second.first;
		int pIdx = pq.top().second.second;
		pq.pop();

		result[0] = arr[cIdx];
		result[1] = arr[pIdx];

		if ((cIdx + 1) < pIdx) {
			pq.emplace(make_pair((double)arr[cIdx + 1] / (double)arr[pIdx], make_pair(cIdx + 1, pIdx)));
		}
	}
	return result;
}
