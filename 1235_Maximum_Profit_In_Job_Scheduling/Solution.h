#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit);
	int jobScheduling2(vector<int> &startTime, vector<int> &endTime, vector<int> &profit);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
