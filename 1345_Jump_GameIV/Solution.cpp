#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <queue>

using std::unordered_map;
using std::queue;
using std::unordered_set;

int Solution::minJumps(vector<int>& arr) {
	unordered_map<int, vector<int>> vIndex;
	unordered_set<int> isTraverse;
	for (int i = arr.size() - 1 ; i >= 0 ; --i) vIndex[arr[i]].emplace_back(i);
	queue<int> cur, next;
	cur.emplace(0);
	int result = 0;
	while (!cur.empty()) {
		int idx = cur.front();
		if (idx == arr.size() - 1) break;

		cur.pop();
		if (idx > 0 && isTraverse.find(idx-1) == isTraverse.end()) {
			isTraverse.emplace(idx-1);
			next.emplace(idx - 1);
		}
		if (isTraverse.find(idx+1) == isTraverse.end()) {
			isTraverse.emplace(idx+1);
			next.emplace(idx+1);
		}
		while (!vIndex[arr[idx]].empty()) {
			int iter = vIndex[arr[idx]].back();
			if (isTraverse.find(iter) == isTraverse.end()) {
				isTraverse.emplace(iter);
				next.emplace(iter);
			}
			vIndex[arr[idx]].pop_back();
		}

		if (cur.empty()) {
			++result;
			cur = move(next);
		}
	}
	return result;
}

