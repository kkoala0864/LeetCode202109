#include <vector>
using std::vector;

class Solution {
public:
	Solution() {
	}
	int removeElement(vector<int> &nums, int val);
	int removeElement2(vector<int> &nums, int val);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
