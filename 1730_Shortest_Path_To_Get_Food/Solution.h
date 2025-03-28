#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int getFood(vector<vector<char>> &grid);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
