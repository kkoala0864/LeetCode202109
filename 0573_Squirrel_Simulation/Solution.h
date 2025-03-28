#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int minDistance(int height, int width, vector<int> &tree, vector<int> &squirrel, vector<vector<int>> &nuts);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
