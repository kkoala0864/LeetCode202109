#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	bool isReflected(vector<vector<int>> &points);
	bool isReflected2(vector<vector<int>> &points);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
