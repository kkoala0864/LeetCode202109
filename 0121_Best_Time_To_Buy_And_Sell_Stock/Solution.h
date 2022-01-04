#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int maxProfit(vector<int>& prices);
	int maxProfit2(vector<int>& prices);
	int maxProfit3(vector<int>& prices);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

