#include <data_type.h>

class TreeAncestor {
public:
	void construct(int cur, int parent, int K, vector<vector<int>>& adj, vector<vector<int>>& up) {
		up[cur][0] = parent;
		for (int i = 1 ; i < K ; ++i) {
			up[cur][i] = up[cur][i-1] == -1 ? -1 : up[up[cur][i-1]][i-1];
		}

		for (const auto& n : adj[cur]) {
			construct(n, cur, K, adj, up);
		}
	}
	TreeAncestor(int n, vector<int>& parent) {
		adj = vector<vector<int>>(n, vector<int>());
		for (int i = 0 ; i < parent.size() ; ++i) {
			if (parent[i] == -1) {
				root = i;
			} else {
				adj[parent[i]].emplace_back(i);
			}
		}
		K = 1;
		while ((1 << K) <= n) {
			++K;
		}
		up = vector<vector<int>>(n, vector<int>(K, -1));
		construct(root, -1, K, adj, up);
	}

	int getKthAncestor(int node, int k) {
		for (int i = 0 ; i < K ; ++i) {
			if ((1 << i) & k) {
				node = up[node][i];
			}
			if (node == -1) return -1;
		}
		return node;
	}

private:
	int K;
	int root;
	vector<vector<int>> up;
	vector<vector<int>> adj;
	virtual ~TreeAncestor() {
	}
	TreeAncestor &operator=(const TreeAncestor &source);
	TreeAncestor(const TreeAncestor &);
};
