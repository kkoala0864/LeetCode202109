#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 3, 2, 2, 1, 3};
	int k = 3;
	Solution *test = new Solution();
	auto result = test->distinctNumbers(input, k);
	for (const auto &iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}
