#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> edges = {{5,0},{5,1},{1,6},{1,7},{5,8},{0,3},{2,4},{5,2}};
	vector<int> values = {3,0,10,0,6,1,1,3,0};
	int k = 8;
	int n = 9;
	Solution* test = new Solution();
	cout << test->maxKDivisibleComponents(n, edges, values, k) << endl;
	return 0;
}

