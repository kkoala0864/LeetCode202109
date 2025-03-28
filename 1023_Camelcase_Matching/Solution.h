#include <data_type.h>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<bool> camelMatch(vector<string> &queries, string pattern);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
