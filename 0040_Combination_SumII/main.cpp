#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {10, 1, 2, 7, 6, 1, 5};
	Solution *test = new Solution();
	vector<vector<int>> result = test->combinationSum(input, 8);
	for (const auto &set : result) {
		for (const auto &iter : set) {
			cout << iter << " ";
		}
		cout << endl;
	}
	cout << endl;
	result = test->combinationSum2(input, 8);
	for (const auto &set : result) {
		for (const auto &iter : set) {
			cout << iter << " ";
		}
		cout << endl;
	}
	return 0;
}
