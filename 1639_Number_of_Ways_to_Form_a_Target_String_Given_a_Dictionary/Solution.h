#include <data_type.h>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	int numWays(vector<string> &words, string target);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
