#include <string>

using std::string;

class Solution {
    public :
        Solution() {}
	string minWindow(string s, string t);
	string minWindow2(string s, string t);
	string minWindow3(string s, string t);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

