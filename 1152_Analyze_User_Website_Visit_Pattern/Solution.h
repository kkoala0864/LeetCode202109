#include <data_type.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
    public :
        Solution() {}
	vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

