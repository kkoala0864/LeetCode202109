#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	long long minimumHealth(vector<int> &damage, int armor);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
