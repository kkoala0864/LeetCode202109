#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2};
	Solution *test = new Solution();
	cout << test->numRescueBoats(input, 3) << endl;
	return 0;
}
