#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {81,54,96,60,58};
	Solution* test = new Solution();
	cout << test->oddEvenJumps(input) << endl;
	return 0;
}

