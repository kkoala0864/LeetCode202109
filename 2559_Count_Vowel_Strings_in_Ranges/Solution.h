#include <data_type.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
