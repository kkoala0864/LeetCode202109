#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int countComponents(int n, vector<vector<int>>& edges);
	int countComponents2(int n, vector<vector<int>>& edges);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

