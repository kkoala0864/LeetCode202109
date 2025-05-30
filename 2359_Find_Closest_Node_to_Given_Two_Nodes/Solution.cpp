#include <Solution.h>

void dfs(vector<int>& edges, int curNode, int level, vector<int>& dis, int type) {
	if (curNode == -1) return;
	if (type == 0) {
		if (dis[curNode] != INT_MIN) return;
	} else {
		if (dis[curNode] != INT_MAX) return;
	}
	dis[curNode] = level;

	dfs(edges, edges[curNode], level + 1, dis, type);
}

int Solution::closestMeetingNode(vector<int>& edges, int node1, int node2) {
	int size = edges.size();
	vector<int> dis1(size, INT_MIN);
	vector<int> dis2(size, INT_MAX);
	dfs(edges, node1, 0, dis1, 0);
	dfs(edges, node2, 0, dis2, 1);

	int result = size;
	int minLen = INT_MAX;
	int max1 = INT_MIN;
	int min2 = INT_MAX;
	for (int i = 0 ; i < size ; ++i) {
		if (dis1[i] == INT_MIN || dis2[i] == INT_MAX) continue;
		int v = max(dis1[i], dis2[i]);
		if (v < minLen) {
			minLen = v;
			result = i;
		}
	}
	return result == size ? -1 : result;
}
