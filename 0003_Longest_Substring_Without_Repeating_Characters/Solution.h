#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	int lengthOfLongestSubstring(string s);
	int lengthOfLongestSubstring2(string s);
	int lengthOfLongestSubstring3(string s);
	int lengthOfLongestSubstring4(string s);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
