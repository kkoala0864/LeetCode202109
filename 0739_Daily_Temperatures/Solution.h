#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<int> dailyTemperatures(vector<int>& temperatures);
	vector<int> dailyTemperatures2(vector<int>& temperatures);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

