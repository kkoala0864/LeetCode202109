#include <data_type.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public :
        Solution() {}
	vector<int> quick_sort(vector<int>& nums);
	int quick_select(vector<int>& nums, int k);
	int binary_search(vector<int>& nums, int target);
	vector<int> dijstra(vector<vector<int>>& edges, int n, int start);
	vector<int> KMPsearch(const string &text, const string &pattern);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

