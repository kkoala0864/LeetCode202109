#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int lengthOfLIS(vector<int> &nums);
	int lengthOfLIS2(vector<int> &nums);
	int lengthOfLIS3(vector<int> &nums);
	int lengthOfLIS4(vector<int> &nums);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
