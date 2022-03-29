#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int findDuplicate(vector<int>& nums);
	int findDuplicate2(vector<int>& nums);
	int findDuplicate3(vector<int>& nums);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

