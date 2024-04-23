#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<int> numIslands2(int m, int n, vector<vector<int>>& positions);
	vector<int> numIslands22(int m, int n, vector<vector<int>>& positions);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

