#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {5, 5, 5, 10, 20};
	Solution *test = new Solution();
	cout << test->lemonadeChange(input) << endl;
	return 0;
}
