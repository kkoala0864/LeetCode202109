#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	void nextPermutation(vector<int>& nums);
	void nextPermutation2(vector<int>& nums);
	void nextPermutation3(vector<int>& nums);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

