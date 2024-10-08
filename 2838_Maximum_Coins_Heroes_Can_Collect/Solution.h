#include <data_type.h>
#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

