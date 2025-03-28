#include <data_type.h>
#include <string>
#include <vector>

using std::vector;

using std::string;

class Solution {
public:
	Solution() {
	}
	vector<string> addOperators(string num, int target);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
