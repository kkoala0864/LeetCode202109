#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2, 0, 2, 1, 1, 0};
	Solution *test = new Solution();
	test->sortColors3(input);
	for (const auto &iter : input) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}
