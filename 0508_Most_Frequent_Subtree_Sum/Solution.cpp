#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::unordered_map;
using std::max;

int SubTreeSum(TreeNode* node, unordered_map<int, int>& uMap) {
	int left = 0, right = 0;
	if (node->left) left = SubTreeSum(node->left, uMap);
	if (node->right) right = SubTreeSum(node->right, uMap);
	++uMap[left+right+node->val];
	return left+right+node->val;
}

vector<int> Solution::findFrequentTreeSum(TreeNode* root) {
	unordered_map<int, int> uMap;
	SubTreeSum(root, uMap);
	vector<int> result;

	int maxFreq = -1;
	for (const auto& iter : uMap) maxFreq = max(maxFreq, iter.second);
	for (const auto& iter : uMap) if (iter.second == maxFreq) result.emplace_back(iter.first);
	return result;
}
