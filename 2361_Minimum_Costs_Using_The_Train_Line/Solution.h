#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

