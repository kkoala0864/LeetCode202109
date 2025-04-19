#include <data_type.h>
#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
	}
	long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
