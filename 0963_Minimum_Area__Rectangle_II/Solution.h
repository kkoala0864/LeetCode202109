#include <data_type.h>
#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	double minAreaFreeRect(vector<vector<int>> &points);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
