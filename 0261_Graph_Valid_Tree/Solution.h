#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	bool validTree(int n, vector<vector<int>>& edges);
	bool validTree2(int n, vector<vector<int>>& edges);
	bool validTree3(int n, vector<vector<int>>& edges);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

