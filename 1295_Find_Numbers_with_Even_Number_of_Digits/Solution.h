#include <data_type.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
	}
	int findNumbers(vector<int>& nums);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
