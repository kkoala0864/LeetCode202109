#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

