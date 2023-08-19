#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> connections = {{1,2,5},{1,3,6},{2,3,1}};
	Solution* test = new Solution();
	cout << test->minimumCost(3, connections) << endl;
	return 0;

}

