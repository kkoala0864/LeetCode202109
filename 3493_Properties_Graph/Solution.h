#include <data_type.h>
#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int numberOfComponents(vector<vector<int>> &properties, int k);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
