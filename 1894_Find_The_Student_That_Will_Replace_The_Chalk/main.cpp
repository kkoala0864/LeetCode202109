#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {5,1,5};
	int k = 22;
	Solution* test = new Solution();
	cout << test->chalkReplacer(input, k) << endl;
	return 0;
}

