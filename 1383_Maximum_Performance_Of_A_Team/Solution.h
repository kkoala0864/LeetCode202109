#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

