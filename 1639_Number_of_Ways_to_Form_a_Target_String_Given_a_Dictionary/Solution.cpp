#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int Solution::numWays(vector<string>& words, string target) {
	int wsize = words[0].size();
	long long mod = 1e9 + 7;
	vector<vector<int>> wIdxCnt(26, vector<int>(wsize, 0));

	for (const auto& w : words) {
		for (int i = 0 ; i < wsize ; ++i) {
			++wIdxCnt[w[i]-'a'][i];
			wIdxCnt[w[i]-'a'][i] %= mod;
		}
	}

	vector<int> last, cur;
	int sum = 0;
	for (int i = 0 ; i < wsize ; ++i) {
		sum += wIdxCnt[target[0]-'a'][i];
		last.emplace_back(sum);
	}
	for (int ti = 1 ; ti < target.size() ; ++ti) {
		char c = target[ti];
		int curSum = 0;
		for (int i = 0 ; i < wsize ; ++i) {
			if (i < ti) {
				cur.emplace_back(0);
			} else {
				long long v = ((long long)wIdxCnt[c-'a'][i] * (long long)last[i-1]) % mod;
				cur.emplace_back((cur.back() + v) % mod);
			}
		}
		last = move(cur);
	}
	return last.back() % mod;
}
