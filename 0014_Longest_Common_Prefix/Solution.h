#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
    public :
        Solution() {}
	string longestCommonPrefix(vector<string>& strs);
	string longestCommonPrefix2(vector<string>& strs);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

