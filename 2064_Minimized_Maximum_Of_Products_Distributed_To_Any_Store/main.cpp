#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {5,7};
	int n = 2;
	Solution* test = new Solution();
	cout << test->minimizedMaximum(n, input) << endl;
	return 0;
}
