#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {8, 3, 4, 7, 6, 6, 9, 2, 5, 8, 2, 4, 9, 5, 9, 1, 5, 7, 1, 4};
	Solution *test = new Solution();
	cout << test->deleteAndEarn(input) << endl;
	cout << test->deleteAndEarn2(input) << endl;
	return 0;
}
