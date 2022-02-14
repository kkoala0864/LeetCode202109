#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
    public :
        Solution() {}
	vector<vector<string>> groupStrings(vector<string>& strings);
	vector<vector<string>> groupStrings2(vector<string>& strings);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

