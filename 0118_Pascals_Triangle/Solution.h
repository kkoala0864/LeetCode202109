#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<vector<int>> generate(int numRows);
	vector<vector<int>> generate2(int numRows);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
