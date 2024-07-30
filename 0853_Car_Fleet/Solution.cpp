#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <stack>

using std::pair;
using std::sort;
using std::stack;
using std::cout;
using std::endl;

int Solution::carFleet(int target, vector<int>& position, vector<int>& speed) {
	vector<pair<int, double>> l;
	for (int i = 0 ; i < position.size() ; ++i) {
		l.emplace_back(pair<int, double>(position[i], (double)(target - position[i]) / (double)speed[i]));
	}
	sort(l.begin(), l.end(), std::greater<pair<int, double>>());

	stack<pair<int, double>> st;

	for (auto& e : l) {
		if (st.empty()) {
			st.emplace(e);
		} else {
			if (e.second > st.top().second) {
				st.emplace(e);
			}
		}
	}
	return st.size();
}
