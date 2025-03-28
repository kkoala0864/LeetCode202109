#include <Solution.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::pair;
using std::priority_queue;
using std::stack;
using std::vector;

string Solution::robotWithString(string s) {
	priority_queue<pair<char, int>, vector<pair<char, int>>, std::greater<pair<char, int>>> pq;
	stack<pair<char, int>> st;
	string result;
	for (int i = 0; i < s.size(); ++i) {
		pq.emplace(pair<char, int>(s[i], i));
	}

	int iter = 0;
	while (!pq.empty()) {
		for (; iter <= pq.top().second; ++iter) {
			st.emplace(pair<char, int>(s[iter], iter));
		}
		pq.pop();

		while (!st.empty() && st.top().first <= pq.top().first) {
			result.push_back(st.top().first);
			st.pop();
		}
	}
	while (!st.empty()) {
		result.push_back(st.top().first);
		st.pop();
	}
	return result;
}
