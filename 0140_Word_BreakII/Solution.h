#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<string> wordBreak(string s, vector<string> &wordDict);
	vector<string> wordBreak2(string s, vector<string> &wordDict);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
