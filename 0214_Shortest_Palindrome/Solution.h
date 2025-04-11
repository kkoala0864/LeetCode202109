#include <data_type.h>
#include <string>

using namespace std;

class Solution {
public:
	Solution() {
	}
	string shortestPalindrome(string s);
	string manacher(string s);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
