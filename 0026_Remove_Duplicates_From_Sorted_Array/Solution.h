#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int removeDuplicates(vector<int> &nums);
	int removeDuplicates2(vector<int> &nums);
	int removeDuplicates3(vector<int> &nums);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
