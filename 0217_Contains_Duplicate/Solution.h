#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	bool containsDuplicate(vector<int> &nums);
	bool containsDuplicate2(vector<int> &nums);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
