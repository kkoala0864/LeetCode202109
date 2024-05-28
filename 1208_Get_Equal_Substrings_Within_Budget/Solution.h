#include <data_type.h>
#include <string>

using std::string;

class Solution {
    public :
        Solution() {}
	int equalSubstring(string s, string t, int maxCost);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

