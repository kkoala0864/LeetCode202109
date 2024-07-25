#include <data_type.h>
#include <vector>

using namespace std;

class Solution {
    public :
        Solution() {}
	vector<int> quick_sort(vector<int>& nums);
	int quick_select(vector<int>& nums, int k);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

