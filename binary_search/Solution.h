#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int general(vector<int>& list, int target);
	int findFirstBiggerThanMe(vector<int>& list, int target);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

