#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	bool validPath(int n, vector<vector<int>>& edges, int source, int destination);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

