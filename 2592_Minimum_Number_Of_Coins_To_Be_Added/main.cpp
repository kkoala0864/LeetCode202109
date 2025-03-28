#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 4, 10};
	Solution *test = new Solution();
	cout << test->minimumAddedCoins(input, 19) << endl;
	return 0;
}
