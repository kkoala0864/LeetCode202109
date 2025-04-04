#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost);
	int canCompleteCircuit2(vector<int> &gas, vector<int> &cost);
	int canCompleteCircuit3(vector<int> &gas, vector<int> &cost);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
