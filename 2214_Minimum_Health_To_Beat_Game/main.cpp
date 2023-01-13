#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,7,4,3};
	Solution* test = new Solution();
	cout << test->minimumHealth(input, 4) << endl;
	return 0;
}

