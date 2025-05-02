#include <data_type.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
	}
	int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
