#include <data_type.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	int largestPathValue(string colors, vector<vector<int>> &edges);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
