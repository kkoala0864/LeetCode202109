#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	void gameOfLife(vector<vector<int>> &board);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
