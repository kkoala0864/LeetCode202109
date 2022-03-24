#include <string>

using std::string;

class Solution {
    public :
        Solution() {}
	bool canWin(string currentState);
	bool canWin2(string currentState);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

