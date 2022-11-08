#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<int> singleNumber(vector<int>& nums);
	vector<int> singleNumber2(vector<int>& nums);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

