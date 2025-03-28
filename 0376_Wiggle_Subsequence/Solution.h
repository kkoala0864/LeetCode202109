#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int wiggleMaxLength(vector<int> &nums);
	int wiggleMaxLength2(vector<int> &nums);
	int wiggleMaxLength3(vector<int> &nums);
	int wiggleMaxLength4(vector<int> &nums);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
