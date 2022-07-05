#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int longestConsecutive(vector<int>& nums);
	int longestConsecutive2(vector<int>& nums);
	int longestConsecutive3(vector<int>& nums);
	int longestConsecutive4(vector<int>& nums);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

