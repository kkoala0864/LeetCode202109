#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	bool isPalindrome(string s);
	bool isPalindrome2(string s);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
