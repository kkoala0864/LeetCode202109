#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	void solveSudoku(vector<vector<char>> &board);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
