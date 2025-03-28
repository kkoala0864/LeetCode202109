#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int minCostConnectPoints(vector<vector<int>> &points);
	int minCostConnectPoints2(vector<vector<int>> &points);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
