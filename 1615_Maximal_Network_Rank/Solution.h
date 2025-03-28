#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int maximalNetworkRank(int n, vector<vector<int>> &roads);
	int maximalNetworkRank2(int n, vector<vector<int>> &roads);
	int maximalNetworkRank3(int n, vector<vector<int>> &roads);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
