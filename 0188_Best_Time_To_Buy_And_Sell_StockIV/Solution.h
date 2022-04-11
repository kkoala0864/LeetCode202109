#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int maxProfit(int k, vector<int>& prices);
	int maxProfit2(int k, vector<int>& prices);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

