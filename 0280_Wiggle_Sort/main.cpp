#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3, 2, 1, 5, 4, 6};
	Solution *test = new Solution();
	test->wiggleSort2(input);
	for (const auto &iter : input) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}
