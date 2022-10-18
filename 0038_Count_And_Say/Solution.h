#include <string>

using std::string;

class Solution {
    public :
        Solution() {}
	string countAndSay(int n);
	string countAndSay2(int n);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

