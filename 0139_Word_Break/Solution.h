#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	bool wordBreak(string s, vector<string> &wordDict);
	bool wordBreak2(string s, vector<string> &wordDict);
	bool wordBreak3(string s, vector<string> &wordDict);
	bool wordBreak4(string s, vector<string> &wordDict);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
