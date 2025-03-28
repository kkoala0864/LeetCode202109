#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int threeSumClosest(vector<int> &nums, int target);
	int threeSumClosest2(vector<int> &nums, int target);
	int threeSumClosest3(vector<int> &nums, int target);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
