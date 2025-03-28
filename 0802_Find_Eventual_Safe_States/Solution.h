#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<int> eventualSafeNodes(vector<vector<int>> &graph);
	vector<int> eventualSafeNodes2(vector<vector<int>> &graph);
	vector<int> eventualSafeNodes3(vector<vector<int>> &graph);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
