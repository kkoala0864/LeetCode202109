#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges);
	vector<int> findMinHeightTrees2(int n, vector<vector<int>> &edges);
	vector<int> findMinHeightTrees3(int n, vector<vector<int>> &edges);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
