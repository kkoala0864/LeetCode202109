#include <data_type.h>

class Solution {
public:
	Solution() {
	}
	long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
