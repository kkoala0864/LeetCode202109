#include <data_type.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
    public :
        Solution() {}
	string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

