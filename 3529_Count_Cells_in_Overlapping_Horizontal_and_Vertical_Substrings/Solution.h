#include <data_type.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
	}
	int countCells(vector<vector<char>>& grid, string pattern);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
