#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	string reverseWords(string s);
	string reverseWords2(string s);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
