#include <data_type.h>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
    public :
        Solution() {}
	string shiftingLetters(string s, vector<vector<int>>& shifts);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

