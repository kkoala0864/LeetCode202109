#include <vector>
using std::vector;

class Solution {
public:
	Solution() {
	}
	int maxArea(vector<int> &height);
	int maxArea2(vector<int> &height);
	int maxArea3(vector<int> &height);
	int maxArea4(vector<int> &height);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
