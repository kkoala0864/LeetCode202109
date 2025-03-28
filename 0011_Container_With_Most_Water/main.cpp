#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2, 3, 4, 5, 18, 17, 6};
	Solution *test = new Solution();
	cout << test->maxArea(input) << endl;
	cout << test->maxArea2(input) << endl;
	cout << test->maxArea3(input) << endl;
	cout << test->maxArea4(input) << endl;
	return 0;
}
