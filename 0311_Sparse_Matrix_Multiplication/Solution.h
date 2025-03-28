#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<vector<int>> multiply(vector<vector<int>> &mat1, vector<vector<int>> &mat2);
	vector<vector<int>> multiply2(vector<vector<int>> &mat1, vector<vector<int>> &mat2);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
