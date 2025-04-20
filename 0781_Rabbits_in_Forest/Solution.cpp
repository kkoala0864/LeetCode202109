#include <Solution.h>
#include <iostream>
#include <unordered_map>

int Solution::numRabbits(vector<int>& answers) {
	unordered_map<int, int> m;
	for (const auto& v : answers) {
		++m[v];
	}

	int result = 0;
	for (const auto& e : m) {
		int cnt = e.first + 1;
		int lv = e.second / cnt + (e.second % cnt > 0);
		result += (lv * cnt);
	}
	return result;
}
