#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	bool possibleBipartition(int n, vector<vector<int>> &dislikes);
	bool possibleBipartition2(int n, vector<vector<int>> &dislikes);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
