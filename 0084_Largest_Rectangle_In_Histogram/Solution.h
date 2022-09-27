#include <vector>
using std::vector;

class Solution {
    public :
        Solution() {}
	int largestRectangleArea(vector<int>& heights);
	int largestRectangleArea2(vector<int>& heights);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

