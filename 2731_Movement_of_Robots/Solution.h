#include <data_type.h>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	int sumDistance(vector<int>& nums, string s, int d);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
