#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int nearestExit(vector<vector<char>>& maze, vector<int>& entrance);
	int nearestExit2(vector<vector<char>>& maze, vector<int>& entrance);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

