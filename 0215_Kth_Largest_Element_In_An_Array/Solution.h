#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int findKthLargest(vector<int> &nums, int k);
	int findKthLargest2(vector<int> &nums, int k);
	int findKthLargest3(vector<int> &nums, int k);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
