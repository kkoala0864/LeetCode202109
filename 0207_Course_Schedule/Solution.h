#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites);
	bool canFinish2(int numCourses, vector<vector<int>>& prerequisites);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

