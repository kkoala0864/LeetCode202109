#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<int> findBall(vector<vector<int>> &grid);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
