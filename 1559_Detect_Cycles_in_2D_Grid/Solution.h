#include <data_type.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
	}
	bool containsCycle(vector<vector<char>>& grid);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
