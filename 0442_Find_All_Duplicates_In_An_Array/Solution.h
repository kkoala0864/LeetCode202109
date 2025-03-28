#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<int> findDuplicates(vector<int> &nums);
	vector<int> findDuplicates2(vector<int> &nums);
	vector<int> findDuplicates3(vector<int> &nums);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
