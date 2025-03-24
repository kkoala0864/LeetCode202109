#include <data_type.h>
#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

