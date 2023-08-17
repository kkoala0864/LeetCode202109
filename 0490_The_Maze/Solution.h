#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

