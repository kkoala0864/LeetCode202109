#include <string>

using std::string;

class Solution {
    public :
        Solution() {}
	int strStr(string haystack, string needle);
	int strStr2(string haystack, string needle);
	int strStr3(string haystack, string needle);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

