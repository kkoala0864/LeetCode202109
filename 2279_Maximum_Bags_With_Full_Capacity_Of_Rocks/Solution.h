#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
