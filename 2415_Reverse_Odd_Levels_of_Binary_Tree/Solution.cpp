#include <Solution.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using std::vector;
using std::queue;
using std::reverse;
using std::cout;
using std::endl;

TreeNode* Solution::reverseOddLevels(TreeNode* root) {
	vector<TreeNode*> last, cur;

	queue<TreeNode*> que, next;

	que.emplace(root);
	last.emplace_back(root);
	int level = 1;

	while (!que.empty()) {
		auto node = que.front();
		que.pop();

		if (node->left) {
			next.emplace(node->left);
			cur.emplace_back(node->left);
			next.emplace(node->right);
			cur.emplace_back(node->right);
		}

		if (que.empty()) {
			que = move(next);
			if (!cur.empty()) {
				if (level & 1) {
					reverse(cur.begin(), cur.end());
				}
				for (int i = 0 ; i < last.size() && !cur.empty() ; ++i) {
					int idx = 2 * i;
					last[i]->left = cur[idx];
					last[i]->right = cur[idx+1];
				}
			}
			++level;
			last = move(cur);
		}
	}
	return root;
}
