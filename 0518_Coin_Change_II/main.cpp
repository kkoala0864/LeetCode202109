#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> coins = {3};
	Solution *test = new Solution();
	cout << test->change(2, coins) << endl;
	return 0;
}
