#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<vector<int>> permute(vector<int>& nums);
	vector<vector<int>> permute2(vector<int>& nums);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

