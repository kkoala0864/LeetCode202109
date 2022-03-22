#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	void sortColors(vector<int>& nums);
	void sortColors2(vector<int>& nums);
	void sortColors3(vector<int>& nums);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

