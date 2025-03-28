#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int singleNumber(vector<int> &nums);
	int singleNumber2(vector<int> &nums);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
