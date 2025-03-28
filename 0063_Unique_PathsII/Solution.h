#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid);
	int uniquePathsWithObstacles2(vector<vector<int>> &obstacleGrid);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
