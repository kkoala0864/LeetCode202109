#include <data_type.h>
#include <string>

using std::string;

using namespace std;

class Solution {
public:
	Solution() {
	}
	int longestPalindrome(string s, string t);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
