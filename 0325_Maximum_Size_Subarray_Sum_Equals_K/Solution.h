#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int maxSubArrayLen(vector<int> &nums, int k);
	int maxSubArrayLen2(vector<int> &nums, int k);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
