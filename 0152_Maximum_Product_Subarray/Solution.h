#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int maxProduct(vector<int> &nums);
	int maxProduct2(vector<int> &nums);
	int maxProduct3(vector<int> &nums);
	int maxProduct4(vector<int> &nums);
	int maxProduct5(vector<int> &nums);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
