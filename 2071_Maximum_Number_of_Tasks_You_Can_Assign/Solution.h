#include <data_type.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
	}
	int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
