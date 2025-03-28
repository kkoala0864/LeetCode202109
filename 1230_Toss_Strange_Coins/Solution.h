#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	double probabilityOfHeads(vector<double> &prob, int target);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
