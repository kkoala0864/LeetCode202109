#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int subarraySum(vector<int> &nums, int k);
	int subarraySum2(vector<int> &nums, int k);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
