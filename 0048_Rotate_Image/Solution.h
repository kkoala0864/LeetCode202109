#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	void rotate(vector<vector<int>> &matrix);
	void rotate2(vector<vector<int>> &matrix);
	void rotate3(vector<vector<int>> &matrix);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
