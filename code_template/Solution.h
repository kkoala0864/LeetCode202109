#include <data_type.h>
#include <vector>

using namespace std;

class Solution {
    public :
        Solution() {}
	vector<int> quick_sort(vector<int>& nums);
	int quick_select(vector<int>& nums, int k);

	int binary_search(vector<int>& nums, int target);
	vector<int> dijstra(vector<vector<int>>& edges, int n, int start);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

