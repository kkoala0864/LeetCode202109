#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<vector<int>> getFactors(int n);
	vector<vector<int>> getFactors2(int n);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

