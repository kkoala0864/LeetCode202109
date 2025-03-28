#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;
using std::sort;

int Solution::hIndex2(vector<int> &citations) {
	auto cmp = [](int lhs, int rhs) { return lhs > rhs; };
	sort(citations.begin(), citations.end(), cmp);
	int cnt = 0;
	int result = 0;
	for (int i = 0; i < citations.size(); ++i) {
		++cnt;
		result = max(result, min(cnt, citations[i]));
	}
	return result;
}

/*
int Solution::hIndex2(vector<int>& citations) {
        vector<int> map(1001, 0);
        for (int i = 0 ; i < citations.size() ; ++i) ++map[citations[i]];
        int cnt = 0;
        int result = 0;
        for (int i = 1000 ; i >= 0 ; --i) {
                if (map[i] > 0) {
                        cnt += map[i];
                        result = max(result, min(cnt, i));
                }
        }
        return result;
}
*/
