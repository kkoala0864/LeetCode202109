#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{2,5,4},{1,5,1}};
	Solution* test = new Solution();
	cout << test->gridGame(input) << endl;
	return 0;
}

