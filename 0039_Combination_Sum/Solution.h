#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<vector<int>> combinationSum(vector<int> &candidates, int target);
	vector<vector<int>> combinationSum2(vector<int> &candidates, int target);
	vector<vector<int>> combinationSum3(vector<int> &candidates, int target);
	vector<vector<int>> combinationSum4(vector<int> &candidates, int target);
	vector<vector<int>> combinationSum5(vector<int> &candidates, int target);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
