#include <Solution.h>
#include <iostream>
#include <climits>

using std::cout;
using std::endl;

int main(void) {
	int input = INT_MAX;
    Solution* test = new Solution();
    cout << test->arrangeCoins(input) << endl;
    cout << test->arrangeCoins2(input) << endl;
    return 0;
}

