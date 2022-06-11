#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int longestIncreasingPath(vector<vector<int>>& matrix);
	int topologicalSort(vector<vector<int>>& matrix);
	int longestIncreasingPath2(vector<vector<int>>& matrix);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

