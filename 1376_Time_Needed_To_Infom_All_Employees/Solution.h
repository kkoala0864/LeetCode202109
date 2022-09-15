#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime);
	int numOfMinutes2(int n, int headID, vector<int>& manager, vector<int>& informTime);
	int numOfMinutes3(int n, int headID, vector<int>& manager, vector<int>& informTime);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

