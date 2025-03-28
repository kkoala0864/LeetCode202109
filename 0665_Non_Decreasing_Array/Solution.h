#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	bool checkPossibility(vector<int> &nums);
	bool checkPossibility2(vector<int> &nums);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
