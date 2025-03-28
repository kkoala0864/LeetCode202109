#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int minReorder(int n, vector<vector<int>> &connections);
	int minReorder2(int n, vector<vector<int>> &connections);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
