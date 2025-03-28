#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	string longestCommonPrefix(vector<string> &strs);
	string longestCommonPrefix2(vector<string> &strs);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
