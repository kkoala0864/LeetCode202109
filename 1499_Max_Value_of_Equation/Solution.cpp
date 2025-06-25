#include <Solution.h>

int Solution::findMaxValueOfEquation(vector<vector<int>>& points, int k) {
	deque<int> deq;

	int result = INT_MIN;
	for (int i = 0 ; i < points.size() ; ++i) {
		while (!deq.empty() && (points[i][0] - points[deq.front()][0]) > k) {
			deq.pop_front();
		}
		if (!deq.empty()) {
			int v = points[deq.front()][1] + points[i][1] + points[i][0] - points[deq.front()][0];
			result = max(result, v);
		}
		int curV = points[i][1] - points[i][0];
		while (!deq.empty() && (points[deq.back()][1] - points[deq.back()][0]) <= curV) {
			deq.pop_back();
		}
		deq.emplace_back(i);
	}
	return result;
}
