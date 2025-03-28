#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

TreeNode *Consrtuct(unordered_map<int, int> &idx, const vector<int> &preorder, const vector<int> &inorder, int pStart, int pEnd, int iStart, int iEnd) {
	if (iStart > iEnd)
		return nullptr;
	if (iStart == iEnd)
		return new TreeNode(preorder[pStart]);

	int loc = idx[preorder[pStart]];
	int cnt = loc - iStart;
	return new TreeNode(preorder[pStart],
	                    Consrtuct(idx, preorder, inorder, pStart + 1, pStart + cnt, iStart, loc - 1),
	                    Consrtuct(idx, preorder, inorder, pStart + cnt + 1, pEnd, loc + 1, iEnd));
}

TreeNode *Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
	int size = preorder.size();
	unordered_map<int, int> idx;
	for (int i = 0; i < inorder.size(); ++i) {
		idx[inorder[i]] = i;
	}
	return Consrtuct(idx, preorder, inorder, 0, size - 1, 0, size - 1);
}
