#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

long long Solution::calculateScore(string s) {
	vector<vector<int>> past(26, vector<int>());
	long long result = 0;
	for (int i = 0 ; i < s.size() ; ++i) {
		int mi = 26 - (s[i] - 'a' + 1);
		if (past[s[i]-'a'].empty()) {
			past[mi].emplace_back(i);
		} else {
			result += ((long long)i - (long long) past[s[i]-'a'].back());
			past[s[i]-'a'].pop_back();
		}
	}
	return result;
}
