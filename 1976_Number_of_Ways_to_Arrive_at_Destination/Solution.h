#include <data_type.h>
#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int countPaths(int n, vector<vector<int>> &roads);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
