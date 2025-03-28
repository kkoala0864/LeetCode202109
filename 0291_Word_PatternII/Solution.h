#include <string>
using std::string;

class Solution {
public:
	Solution() {
	}
	bool wordPatternMatch(string pattern, string s);
	bool wordPatternMatch2(string pattern, string s);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
