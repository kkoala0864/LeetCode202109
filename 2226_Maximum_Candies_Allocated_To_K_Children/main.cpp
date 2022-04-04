#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {5,8,6};
	Solution* test = new Solution();
	cout << test->maximumCandies(input, 3) << endl;
	return 0;
}

