#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int missingNumber(vector<int> &nums);
	int missingNumber2(vector<int> &nums);
	int missingNumber3(vector<int> &nums);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
