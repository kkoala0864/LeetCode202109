#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries);
	vector<double> calcEquation2(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
