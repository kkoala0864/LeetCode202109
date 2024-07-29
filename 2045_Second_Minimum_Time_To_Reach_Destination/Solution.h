#include <data_type.h>
#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int secondMinimum(int n, vector<vector<int>>& edges, int time, int change);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

