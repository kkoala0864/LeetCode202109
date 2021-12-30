#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<vector<int>> threeSum(vector<int>& nums);
	vector<vector<int>> threeSum2(vector<int>& nums);
	vector<vector<int>> threeSum3(vector<int>& nums);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

