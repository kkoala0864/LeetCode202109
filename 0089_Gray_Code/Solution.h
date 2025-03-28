#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<int> grayCode(int n);
	vector<int> grayCode2(int n);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
