#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	int longestSubstring(string s, int k);
	int longestSubstring2(string s, int k);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
