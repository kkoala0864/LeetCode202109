#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<int> twoSum(vector<int>& nums, int target);
	vector<int> twoSum2(vector<int>& nums, int target);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

