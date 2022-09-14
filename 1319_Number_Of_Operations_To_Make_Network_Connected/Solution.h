#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int makeConnected(int n, vector<vector<int>>& connections);
	int makeConnected2(int n, vector<vector<int>>& connections);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

