#include <Solution.h>

int Solution::kthLargestValue(vector<vector<int>>& matrix, int k) {
	priority_queue<int> pq;

	vector<int> pre;
	int m = matrix.size();
	int n = matrix[0].size();
	for (int i = 0 ; i < m ; ++i) {
		vector<int> next = matrix[i];
		for (int j = 0 ; j < n ; ++j) {
			if (j > 0) {
				next[j] ^= next[j-1];;
			}
			if (i > 0) {
				next[j] ^= pre[j];
			}
			if (i > 0 && j > 0) {
				next[j] ^= pre[j-1];
			}
			pq.emplace(next[j]);
		}
		pre = move(next);
	}
	while (--k > 0) pq.pop();
	return pq.top();
}
