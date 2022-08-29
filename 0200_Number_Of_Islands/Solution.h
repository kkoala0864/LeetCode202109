#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int numIslands(vector<vector<char>>& grid);
	int numIslands2(vector<vector<char>>& grid);
	int numIslands3(vector<vector<char>>& grid);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

