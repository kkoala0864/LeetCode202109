#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0, 1, 0, 3, 12};
	Solution *test = new Solution();
	test->moveZeroes2(input);
	for (const auto &iter : input) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}
