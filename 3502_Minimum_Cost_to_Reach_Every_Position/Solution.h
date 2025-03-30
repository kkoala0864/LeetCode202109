#include <data_type.h>
#include <vector>

using std::vector;

using namespace std;

class Solution {
public:
	Solution() {
	}
	vector<int> minCosts(vector<int> &cost);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
