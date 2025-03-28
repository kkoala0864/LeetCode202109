#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 3, 4};
	Solution *test = new Solution();
	vector<int> result = test->productExceptSelf(input);
	for (const auto &iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	result = test->productExceptSelf3(input);
	for (const auto &iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}
