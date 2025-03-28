#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int shipWithinDays(vector<int> &weights, int days);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
