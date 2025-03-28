#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	int countSubstrings(string s);
	int countSubstrings2(string s);
	int countSubstrings3(string s);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
