#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> piles = {9, 8, 7, 6, 5, 1, 2, 3, 4};
	Solution *test = new Solution();
	cout << test->maxCoins(piles) << endl;
	return 0;
}
