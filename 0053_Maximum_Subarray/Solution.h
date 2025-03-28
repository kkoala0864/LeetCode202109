#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int maxSubArray(vector<int> &nums);
	int maxSubArray2(vector<int> &nums);
	int maxSubArray3(vector<int> &nums);
	int maxSubArray4(vector<int> &nums);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
