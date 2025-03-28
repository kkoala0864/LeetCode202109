#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2, 3, 1};
	Solution *test = new Solution();
	test->nextPermutation(input);
	for (const auto iter : input) {
		cout << iter << " ";
	}
	cout << endl;
	cout << endl;
	input = {2, 3, 1};
	test->nextPermutation3(input);
	for (const auto iter : input) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}
