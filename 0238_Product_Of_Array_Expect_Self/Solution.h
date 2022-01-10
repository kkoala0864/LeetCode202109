#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<int> productExceptSelf(vector<int>& nums);
	vector<int> productExceptSelf2(vector<int>& nums);
	vector<int> productExceptSelf3(vector<int>& nums);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

