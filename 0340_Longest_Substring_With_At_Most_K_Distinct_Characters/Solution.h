#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	int lengthOfLongestSubstringKDistinct(string s, int k);
	int lengthOfLongestSubstringKDistinct2(string s, int k);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
