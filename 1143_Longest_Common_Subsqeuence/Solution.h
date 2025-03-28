#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	int longestCommonSubsequence(string text1, string text2);
	int longestCommonSubsequence2(string text1, string text2);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
