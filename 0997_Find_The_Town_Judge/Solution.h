#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int findJudge(int n, vector<vector<int>> &trust);
	int findJudge2(int n, vector<vector<int>> &trust);
	int findJudge3(int n, vector<vector<int>> &trust);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
