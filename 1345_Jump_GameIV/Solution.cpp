#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>

using std::unordered_map;
using std::min;

void dfs(vector<int>& arr, unordered_map<int, vector<int>>& vIndex, int idx, int cnt, int& result) {
	if (cnt >= result) return;
	if (idx == arr.size() - 1) {
		result = min(result, cnt);
		return;
	}

	int ori = arr[idx];
	arr[idx] = INT_MAX;
	for (const auto& iter : vIndex[ori]) {
		if (arr[iter] != INT_MAX) {
			dfs(arr, vIndex, iter, cnt + 1, result);
		}
	}
	if (idx > 0 && arr[idx-1] != INT_MAX) dfs(arr, vIndex, idx - 1, cnt + 1, result);
	if (arr[idx + 1] != INT_MAX) dfs(arr, vIndex, idx + 1, cnt + 1, result);
	arr[idx] = ori;
}

int Solution::minJumps(vector<int>& arr) {
	unordered_map<int, vector<int>> vIndex;

	for (int i = arr.size() - 1 ; i >= 0 ; --i) vIndex[arr[i]].emplace_back(i);
	int result = vIndex.size();
	dfs(arr, vIndex, 0, 0, result);
	return result;
}
