#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int numBusesToDestination(vector<vector<int>> &routes, int source, int target);
	int numBusesToDestination2(vector<vector<int>> &routes, int source, int target);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
