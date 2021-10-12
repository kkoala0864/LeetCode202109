#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
/*
void DFS(vector<bool>& flag, int n, vector<int>& result) {
	if (result.size() == flag.size()) return;
	for (int i = 0 ; i < n ; ++i) {
		int nextVal = result.back() ^ (1 << i);
		if (flag[nextVal]) continue;
		else {
			flag[nextVal] = true;
			result.emplace_back(nextVal);
			DFS(flag, n, result);
			break;
		}
	}
}

vector<int> Solution::grayCode(int n) {
	int size = pow(2, n);
	vector<bool> flag(size, false);
	vector<int> result;
	flag[0] = true;
	result.emplace_back(0);
	DFS(flag, n, result);
	return result;
}
*/
vector<int> Solution::grayCode(int n) {
	vector<int> result;
	for (int i = 0 ; i < (1<<n) ; ++i) {
		result.emplace_back(i^(i>>1));
	}
	return result;
}

