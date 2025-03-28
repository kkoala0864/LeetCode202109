#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	bool carPooling(vector<vector<int>> &trips, int capacity);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
