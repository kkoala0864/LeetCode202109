#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<int> maxSlidingWindow(vector<int> &nums, int k);
	vector<int> dp(vector<int> &nums, int k);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
