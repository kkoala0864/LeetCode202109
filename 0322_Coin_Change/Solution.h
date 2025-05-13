#include <data_type.h>

class Solution {
public:
	Solution() {
	}
	int coinChange(vector<int> &coins, int amount);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
