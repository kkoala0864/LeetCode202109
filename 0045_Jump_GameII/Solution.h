#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int jump(vector<int> &nums);
	int jump2(vector<int> &nums);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
