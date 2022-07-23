#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::max;
using std::min;

class Solution {
    public :
        Solution() {}
	vector<int> SegTree(vector<int>& nums);
	vector<int> countSmaller(vector<int>& nums);
	vector<int> countSmaller2(vector<int>& nums);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

