#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<int> majorityElement(vector<int>& nums);
	vector<int> majorityElement2(vector<int>& nums);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

