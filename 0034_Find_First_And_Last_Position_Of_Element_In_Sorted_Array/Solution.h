#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<int> searchRange(vector<int> &nums, int target);
	vector<int> searchRange2(vector<int> &nums, int target);
	vector<int> searchRange3(vector<int> &nums, int target);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
