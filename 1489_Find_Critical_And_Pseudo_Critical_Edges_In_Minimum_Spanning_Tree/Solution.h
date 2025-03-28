#include <data_type.h>
#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
