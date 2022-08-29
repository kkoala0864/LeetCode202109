#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);
	vector<int> findOrder2(int numCourses, vector<vector<int>>& prerequisites);
	vector<int> findOrder3(int numCourses, vector<vector<int>>& prerequisites);
	vector<int> findOrder4(int numCourses, vector<vector<int>>& prerequisites);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

