#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int largestSubmatrix(vector<vector<int>> &matrix);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
