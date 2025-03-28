#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	bool isValidSudoku(vector<vector<char>> &board);
	bool isValidSudoku2(vector<vector<char>> &board);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
