#include <Solution.h>
#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::priority_queue;
using std::pair;

int Solution::kthSmallest(vector<vector<int>>& matrix, int k) {
	int m = matrix.size();

	vector<vector<int>::iterator> iv;
	priority_queue<pair<int , int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
	for (int i = 0 ; i < m ; ++i) {
		iv.emplace_back(matrix[i].begin());
		pq.emplace(*iv[i], i);
	}

	while (--k > 0) {
		auto cur = pq.top();
		pq.pop();
		++iv[cur.second];
		if (iv[cur.second] != matrix[cur.second].end()) pq.emplace(*iv[cur.second], cur.second);
	}
	return pq.top().first;
}
