#include <data_type.h>

class Solution {
public:
	Solution() {
	}
	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
