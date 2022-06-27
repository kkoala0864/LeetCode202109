#include <string>

using std::string;

class Solution {
    public :
        Solution() {}
	int minCut(string s);
	int minCut2(string s);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

