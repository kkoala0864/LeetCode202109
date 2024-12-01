#include <data_type.h>
#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};
