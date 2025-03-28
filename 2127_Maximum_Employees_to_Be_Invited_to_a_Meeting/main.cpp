#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 0, 0, 2, 1, 4};
	Solution *test = new Solution();
	cout << test->maximumInvitations(input) << endl;
	return 0;
}
