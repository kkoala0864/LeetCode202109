#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int minimumTotal(vector<vector<int>> &triangle);
	int minimumTotal2(vector<vector<int>> &triangle);
	int minimumTotal3(vector<vector<int>> &triangle);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
