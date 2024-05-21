#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<vector<int>> subsets(vector<int>& nums);
	vector<vector<int>> subsets2(vector<int>& nums);
	vector<vector<int>> subsets3(vector<int>& nums);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

