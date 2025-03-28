#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int findCircleNum(vector<vector<int>> &isConnected);
	int findCircleNum2(vector<vector<int>> &isConnected);
	int findCircleNum3(vector<vector<int>> &isConnected);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
