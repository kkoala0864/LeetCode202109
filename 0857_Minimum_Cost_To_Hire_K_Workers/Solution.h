#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
