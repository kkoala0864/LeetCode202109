#include <data_type.h>
#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
	}
	int numberOfArrays(vector<int>& differences, int lower, int upper);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
