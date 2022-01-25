#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
    public :
        Solution() {}
	vector<string> findItinerary(vector<vector<string>>& tickets);
	vector<string> findItinerary2(vector<vector<string>>& tickets);
	vector<string> findItinerary3(vector<vector<string>>& tickets);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

