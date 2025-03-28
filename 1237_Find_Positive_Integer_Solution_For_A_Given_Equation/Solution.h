#include <data_type.h>
#include <vector>

using std::vector;

class CustomFunction {
public:
	// Returns f(x, y) for any given positive integers x and y.
	// Note that f(x, y) is increasing with respect to both x and y.
	// i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
	int f(int x, int y);
};

class Solution {
public:
	Solution() {
	}
	vector<vector<int>> findSolution(CustomFunction &customfunction, int z);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
