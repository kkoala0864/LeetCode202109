#include <data_type.h>
#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<vector<int>> divideArray(vector<int> &nums, int k);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
