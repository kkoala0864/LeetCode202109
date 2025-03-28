#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<vector<int>> updateMatrix(vector<vector<int>> &mat);
	vector<vector<int>> updateMatrix2(vector<vector<int>> &mat);
	vector<vector<int>> updateMatrix3(vector<vector<int>> &mat);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
