#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<vector<int>> merge(vector<vector<int>> &intervals);
	vector<vector<int>> merge2(vector<vector<int>> &intervals);
	vector<vector<int>> merge3(vector<vector<int>> &intervals);
	vector<vector<int>> merge4(vector<vector<int>> &intervals);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
