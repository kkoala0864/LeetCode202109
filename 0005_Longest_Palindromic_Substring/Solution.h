#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	string longestPalindrome(string s);
	string longestPalindrome2(string s);
	string longestPalindrome3(string s);
	string longestPalindrome4(string s);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
