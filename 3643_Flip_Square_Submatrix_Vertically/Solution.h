#include <data_type.h>

class Solution {
public:
	Solution() {
	}
	vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
