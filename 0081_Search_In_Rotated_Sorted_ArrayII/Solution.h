#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	bool search(vector<int> &nums, int target);
	bool search2(vector<int> &nums, int target);
	bool search3(vector<int> &nums, int target);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
