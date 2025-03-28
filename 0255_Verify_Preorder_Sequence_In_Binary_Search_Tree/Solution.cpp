#include <Solution.h>
#include <iostream>
#include <climits>

bool dfs(vector<int> &preorder, int start, int end, int lower_bound, int upper_bound) {
	if (start > end)
		return true;

	int root = preorder[start];
	if (root < lower_bound || root > upper_bound)
		return false;

	int rightStart = start + 1;
	for (; rightStart <= end; ++rightStart) {
		if (preorder[rightStart] > root)
			break;
	}
	return dfs(preorder, start + 1, rightStart - 1, lower_bound, root) && dfs(preorder, rightStart, end, root, upper_bound);
}

bool Solution::verifyPreorder(vector<int> &preorder) {
	return dfs(preorder, 0, preorder.size() - 1, INT_MIN, INT_MAX);
}
