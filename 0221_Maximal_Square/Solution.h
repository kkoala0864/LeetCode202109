#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int maximalSquare(vector<vector<char>> &matrix);
	int maximalSquare2(vector<vector<char>> &matrix);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
