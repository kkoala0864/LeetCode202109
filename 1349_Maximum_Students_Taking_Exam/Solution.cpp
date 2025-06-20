#include <Solution.h>

int Solution::maxStudents(vector<vector<char>>& seats) {
	int m = seats.size();
	int n = seats[0].size();

	vector<unordered_map<int, int>> states;
	for (int i = 0 ; i < m ; ++i) {
		unordered_map<int, int> state;
		state[0] = 0;
		for (int j = 0 ; j < n ; ++j) {
			if (seats[i][j] == '#') continue;
			unordered_map<int, int> next = state;
			for (const auto& s : state) {
				if (j > 0 && (s.first & (1 << (j-1)))) continue;
				next[s.first | (1 << j)] = s.second + 1;
			}
			state = next;
		}
		states.emplace_back(state);
	}
	unordered_map<int, int> dp = states[0];
	for (int i = 1 ; i < m ; ++i) {
		unordered_map<int, int> next;
		for (const auto& e1 : dp) {
			for (const auto& e2 : states[i]) {
				if (((e1.first << 1) & e2.first) || ((e1.first >> 1) & e2.first)) continue;
				next[e2.first] = max(next[e2.first], e1.second + e2.second);
			}
		}
		dp = std::move(next);
	}
	int result = 0;
	for (const auto& v : dp) {
		result = max(result, v.second);
	}
	return result;
}
