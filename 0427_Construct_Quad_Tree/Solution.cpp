#include <Solution.h>

Node* dfs(vector<vector<int>>& grid, int x, int y, int size) {
	if (size == 1) {
		return new Node(grid[x][y], true);
	}

	int hs = size / 2;
	vector<Node*> child = {dfs(grid, x, y, hs),
			dfs(grid, x, y + hs, hs),
			dfs(grid, x + hs, y, hs),
			dfs(grid, x + hs, y + hs, hs)
	};

	Node* cur = new Node(grid[x][y], true);
	int val = 0;
	for (const auto& n : child) {
		val += n->val;
		if (n->isLeaf) continue;
		cur->isLeaf = false;
		break;
	}
	cur->isLeaf &= (val == 0 || val == 4);
	if (cur->isLeaf) {
		cur->val = val / 4;
	} else {
		cur->topLeft = child[0];
		cur->topRight = child[1];
		cur->bottomLeft = child[2];
		cur->bottomRight = child[3];
	}
	return cur;
}

Node* Solution::construct(vector<vector<int>>& grid) {
	int size = grid.size();
	return dfs(grid, 0, 0, size);
}
