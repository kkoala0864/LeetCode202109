#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;
using std::cout;
using std::endl;

int Solution::minMoves(vector<vector<int>>& rooks) {
	int n = rooks.size();
	priority_queue<int, vector<int>, std::greater<int>> xpq, ypq;

	for (int i = 0 ; i < n ; ++i) {
		xpq.emplace(rooks[i][0]);
		ypq.emplace(rooks[i][1]);
	}

	int result = 0;
	for (int i = 0 ; i < n ; ++i) {
		result += abs(i-xpq.top());
		result += abs(i-ypq.top());

		xpq.pop();
		ypq.pop();
	}
	return result;
}
