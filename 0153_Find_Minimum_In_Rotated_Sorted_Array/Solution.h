#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int findMin(vector<int>& nums);
	int findMin2(vector<int>& nums);
	int findMin3(vector<int>& nums);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

