#include <data_type.h>

class Solution {
public:
	Solution() {
	}
	vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
