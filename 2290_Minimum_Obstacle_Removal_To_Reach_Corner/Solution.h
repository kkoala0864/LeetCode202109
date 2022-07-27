#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int minimumObstacles(vector<vector<int>>& grid);
	int minimumObstacles2(vector<vector<int>>& grid);
	int Dijkstra(vector<vector<int>>& grid);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

