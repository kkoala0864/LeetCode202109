#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0,0,0,0};
	Solution* test = new Solution();
	for (const auto iter : test->threeSum(input)) {
		for (const auto iter2 : iter) {
			cout << iter2 << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (const auto iter : test->threeSum2(input)) {
		for (const auto iter2 : iter) {
			cout << iter2 << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (const auto iter : test->threeSum3(input)) {
		for (const auto iter2 : iter) {
			cout << iter2 << " ";
		}
		cout << endl;
	}
	return 0;
}

