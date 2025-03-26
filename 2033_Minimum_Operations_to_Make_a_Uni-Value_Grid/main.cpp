#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{931,128},{639,712}};
	int x = 73;
	Solution* test = new Solution();
	cout << test->minOperations(input, x) << endl;
	return 0;
}

