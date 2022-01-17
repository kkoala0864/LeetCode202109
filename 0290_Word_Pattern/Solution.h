#include <string>

using std::string;

class Solution {
    public :
        Solution() {}
	bool wordPattern(string pattern, string s);
	bool wordPattern2(string pattern, string s);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

