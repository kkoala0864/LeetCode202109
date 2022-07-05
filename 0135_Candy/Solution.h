#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int candy(vector<int>& ratings);
	int twoArray(vector<int>& ratings);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

