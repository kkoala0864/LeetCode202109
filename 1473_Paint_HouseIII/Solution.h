#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

