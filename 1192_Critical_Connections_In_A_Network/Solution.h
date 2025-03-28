#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections);
	vector<vector<int>> criticalConnections2(int n, vector<vector<int>> &connections);
	vector<vector<int>> criticalConnections3(int n, vector<vector<int>> &connections);
	vector<vector<int>> Tarjan(int n, vector<vector<int>> &connections);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
