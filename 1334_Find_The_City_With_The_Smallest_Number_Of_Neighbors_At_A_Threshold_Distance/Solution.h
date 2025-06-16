#include <data_type.h>

class Solution {
public:
	Solution() {
	}
	int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
