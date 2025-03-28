#include <data_type.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	double maxAmount(string initialCurrency, vector<vector<string>> &pairs1, vector<double> &rates1, vector<vector<string>> &pairs2, vector<double> &rates2);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
