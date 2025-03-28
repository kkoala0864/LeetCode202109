#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 3, 2};
	Solution *test = new Solution();
	cout << test->kEmptySlots(input, 1) << endl;
	return 0;
}
