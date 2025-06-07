#include <data_type.h>

class Solution {
public:
	Solution() {
	}
	long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
