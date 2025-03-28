#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets);
	string findReplaceString2(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
