#include <data_type.h>
#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

