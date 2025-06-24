#include <data_type.h>

class Solution {
public:
	Solution() {
	}
	int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
