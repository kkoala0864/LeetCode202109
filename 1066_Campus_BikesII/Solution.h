#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int assignBikes(vector<vector<int>> &workers, vector<vector<int>> &bikes);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
