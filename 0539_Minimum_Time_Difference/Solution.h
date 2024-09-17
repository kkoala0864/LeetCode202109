#include <data_type.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
    public :
        Solution() {}
	int findMinDifference(vector<string>& timePoints);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

