#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int superPow(int a, vector<int>& b);
	int superPow2(int a, vector<int>& b);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

