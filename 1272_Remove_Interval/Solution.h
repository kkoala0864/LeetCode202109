#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<vector<int>> removeInterval(vector<vector<int>> &intervals, vector<int> &toBeRemoved);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
