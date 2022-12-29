#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<int> getOrder(vector<vector<int>>& tasks);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

