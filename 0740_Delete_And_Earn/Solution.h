#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int deleteAndEarn(vector<int> &nums);
	int deleteAndEarn2(vector<int> &nums);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
