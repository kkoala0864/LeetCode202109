#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{2,5,3},{8,12,4}};
	Solution* test = new Solution();
	cout << test->separateSquares(input) << endl;
	return 0;
}

