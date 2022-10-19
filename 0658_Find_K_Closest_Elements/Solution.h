#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<int> findClosestElements(vector<int>& arr, int k, int x);
	vector<int> findClosestElements2(vector<int>& arr, int k, int x);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

