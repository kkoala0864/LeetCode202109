#include <Solution.h>

bool dfs(vector<int>& preorder, int rv, int ps, int pe, int lower, int upper) {
	if (ps > pe) return true;
	if (ps == pe) return preorder[ps] > lower && preorder[ps] < upper;

	int rs = ps;
	for (; rs <= pe ; ++rs) {
		if (preorder[rs] < lower || preorder[rs] > upper) return false;
		if (preorder[rs] < rv) continue;
		break;
	}
	if (rs > ps) {
		if (!dfs(preorder, preorder[ps], ps + 1, rs - 1, lower, rv)) return false;
	}
	if (rs <= pe) {
		if (!dfs(preorder, preorder[rs], rs + 1, pe, rv, upper)) return false;
	}
	return true;
}

bool Solution::verifyPreorder(vector<int> &preorder) {
	return dfs(preorder, preorder[0], 1, preorder.size() - 1, 0, INT_MAX);
}
