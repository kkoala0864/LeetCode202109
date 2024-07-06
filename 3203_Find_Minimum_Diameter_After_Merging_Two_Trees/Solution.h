#include <data_type.h>
#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

