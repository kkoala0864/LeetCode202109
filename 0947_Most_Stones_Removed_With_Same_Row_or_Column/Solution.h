#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int removeStones(vector<vector<int>>& stones);
	int removeStones2(vector<vector<int>>& stones);
	int removeStones3(vector<vector<int>>& stones);
	int removeStones4(vector<vector<int>>& stones);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

