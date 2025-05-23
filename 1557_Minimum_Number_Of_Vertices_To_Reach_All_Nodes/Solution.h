#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges);
	vector<int> findSmallestSetOfVertices2(int n, vector<vector<int>> &edges);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
