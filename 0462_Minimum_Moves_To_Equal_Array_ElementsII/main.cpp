#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,0,0,8,6};
	Solution* test = new Solution();
	cout << test->minMoves2(input) << endl;
	return 0;
}

