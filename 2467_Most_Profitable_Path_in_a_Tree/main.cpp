#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,1},{1,2},{2,3}};
	int bob = 3;
	vector<int> amount = {-5644,-6018,1188,-8502};
	Solution* test = new Solution();
	cout << test->mostProfitablePath(input, bob, amount) << endl;
	return 0;
}

