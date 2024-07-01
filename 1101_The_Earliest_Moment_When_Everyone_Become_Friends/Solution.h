#include <data_type.h>
#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int earliestAcq(vector<vector<int>>& logs, int n);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

