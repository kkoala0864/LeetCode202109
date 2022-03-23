#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::max;

int getSum(TreeNode* node, unordered_map<int, int>& cnt, int& maxCnt) {
	if (!node) return 0;
	int sum = 0;
	sum += getSum(node->left, cnt, maxCnt) + getSum(node->right, cnt, maxCnt) + node->val;
	++cnt[sum];
	maxCnt = max(maxCnt, cnt[sum]);
	return sum;
}

vector<int> Solution::findFrequentTreeSum2(TreeNode* root) {
	unordered_map<int, int> cnt;
	int maxCnt = 0;
	getSum(root, cnt, maxCnt);
	vector<int> result;
	for (const auto& iter : cnt) {
		if (iter.second == maxCnt) {
			result.emplace_back(iter.first);
		}
	}
	return result;
}
