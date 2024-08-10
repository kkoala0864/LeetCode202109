#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {" /","/ "};
	Solution* test = new Solution();
	cout << test->regionsBySlashes(input) << endl;
	return 0;
}

