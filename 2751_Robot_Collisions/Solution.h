#include <data_type.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
    public :
        Solution() {}
	vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

