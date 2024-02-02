#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int shortestBridge(vector<vector<int>>& grid);
	int shortestBridge2(vector<vector<int>>& grid);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

