#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) ;
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

