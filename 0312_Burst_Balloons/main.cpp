#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3, 1, 5, 8};
	Solution *test = new Solution();
	cout << test->maxCoins(input) << endl;
	return 0;
}
