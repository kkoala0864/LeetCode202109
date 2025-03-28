#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {

	Solution *test = new Solution();
	cout << test->climbStairs(45) << endl;
	cout << test->climbStairs2(45) << endl;
	return 0;
}
