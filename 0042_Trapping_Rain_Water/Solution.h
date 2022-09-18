#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int trap(vector<int>& height);
	int trap2(vector<int>& height);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

