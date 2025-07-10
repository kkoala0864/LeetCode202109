#include <Solution.h>

vector<int> Solution::goodDaysToRobBank(vector<int>& security, int time) {
	int size = security.size();
	vector<int> preCnt(size, 0), postCnt(size, 0);

	preCnt[0] = 1;
	for (int i = 1 ; i < size ; ++i) {
		if (security[i] <= security[i-1]) {
			preCnt[i] = preCnt[i-1] + 1;
		} else {
			preCnt[i] = 1;
		}
	}

	postCnt.back() = 1;
	for (int i = size - 2 ; i >= 0 ; --i) {
		if (security[i] <= security[i+1]) {
			postCnt[i] = postCnt[i+1] + 1;
		} else {
			postCnt[i] = 1;
		}
	}

	vector<int> result;
	for (int i = time ; i < (size - time) ; ++i) {
		if (preCnt[i] >= (time+1) && postCnt[i] >= (time+1)) {
			result.emplace_back(i);
		}
	}
	return result;
}
