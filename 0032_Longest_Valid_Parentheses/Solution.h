#include <string>

using std::string;

class Solution {
    public :
        Solution() {}
	int longestValidParentheses(string s);
	int longestValidParentheses2(string s);
	int longestValidParentheses3(string s);
	int DP(string s);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

