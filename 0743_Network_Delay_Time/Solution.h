#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int networkDelayTime(vector<vector<int>>& times, int n, int k);
	int networkDelayTime2(vector<vector<int>>& times, int n, int k);
	int Dijkstra(vector<vector<int>>& times, int n, int k);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

