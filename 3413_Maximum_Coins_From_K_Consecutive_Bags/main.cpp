#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> coins = {{8, 10, 1}, {1, 3, 2}, {5, 6, 4}};
	int k = 4;
	Solution *test = new Solution();
	cout << test->maximumCoins(coins, k) << endl;
	return 0;
}
