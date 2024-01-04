#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"0"};
	Solution* test = new Solution();
	cout << test->numberOfBeams(input) << endl;
	return 0;
}

