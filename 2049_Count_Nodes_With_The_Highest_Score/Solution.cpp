#include <Solution.h>
#include <iostream>

int countNode(const vector<vector<int>> &node, vector<int> &subCnt, int cur) {
	if (node[cur].empty())
		return 1;
	if (subCnt[cur] != 0)
		return subCnt[cur];

	int result = 0;
	for (int i = 0; i < node[cur].size(); ++i) {
		result += countNode(node, subCnt, node[cur][i]);
	}
	subCnt[cur] = result + 1;
	return result + 1;
}

int Solution::countHighestScoreNodes(vector<int> &parents) {
	vector<vector<int>> node(parents.size(), vector<int>());
	vector<int> subCnt(parents.size(), 0);
	long long maxVal = 0;
	int cnt = 0;
	int root = 0;
	for (int i = 0; i < parents.size(); ++i) {
		if (parents[i] == -1)
			root = i;
		else
			node[parents[i]].emplace_back(i);
	}

	for (int i = 0; i < node.size(); ++i) {
		long long localProduct = 1;
		if (node[i].empty())
			localProduct = parents.size() - 1;
		else {
			int rootSize = parents.size();
			for (const auto &iter : node[i]) {
				int subSize = countNode(node, subCnt, iter);
				localProduct *= subSize;
				rootSize -= subSize;
			}
			if (i != root) {
				localProduct *= (rootSize - 1);
			}
		}

		if (localProduct > maxVal) {
			maxVal = localProduct;
			cnt = 1;
		} else if (localProduct == maxVal) {
			++cnt;
		}
	}
	return cnt;
}
