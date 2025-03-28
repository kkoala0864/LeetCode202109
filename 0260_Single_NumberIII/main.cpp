#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 1, 3, 2, 5};
	Solution *test = new Solution();
	vector<int> result = test->singleNumber(input);
	for (const auto &iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	result = test->singleNumber2(input);
	for (const auto &iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}
