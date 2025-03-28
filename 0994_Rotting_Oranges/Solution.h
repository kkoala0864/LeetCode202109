#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int orangesRotting(vector<vector<int>> &grid);
	int orangesRotting2(vector<vector<int>> &grid);
	int orangesRotting3(vector<vector<int>> &grid);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
