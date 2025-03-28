#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 3, 3};
	Solution *test = new Solution();
	cout << test->findSpecialInteger(input) << endl;
	return 0;
}
