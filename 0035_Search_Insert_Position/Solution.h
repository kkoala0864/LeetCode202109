#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int searchInsert(vector<int> &nums, int target);
	int searchInsert2(vector<int> &nums, int target);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
