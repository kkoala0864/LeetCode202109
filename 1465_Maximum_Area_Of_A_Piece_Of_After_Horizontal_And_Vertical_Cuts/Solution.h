#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

