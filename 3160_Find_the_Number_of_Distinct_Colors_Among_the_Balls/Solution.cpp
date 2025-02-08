#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

vector<int> Solution::queryResults(int limit, vector<vector<int>>& queries) {
	unordered_map<int, int> ball;
	unordered_map<int, int> m;
	vector<int> result;
	for (const auto& q : queries) {
		if (ball.count(q[0])) {
			--m[ball[q[0]]];
			if (m[ball[q[0]]] == 0) m.erase(ball[q[0]]);
		}
		ball[q[0]] = q[1];
		++m[q[1]];
		result.emplace_back(m.size());
	}
	return result;
}
