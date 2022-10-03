#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,2},{2,3},{3,4},{1,4},{1,5}};
	Solution* test = new Solution();
	auto result = test->findRedundantConnection(input);
	cout << result[0] << " : " << result[1] << endl;
	return 0;
}

