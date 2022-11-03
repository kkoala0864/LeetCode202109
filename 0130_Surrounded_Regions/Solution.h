#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	void solve(vector<vector<char>>& board);
	void solve2(vector<vector<char>>& board);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

