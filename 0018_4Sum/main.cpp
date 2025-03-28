#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2, 2, 2, 2, 2};
	Solution *test = new Solution();
	vector<vector<int>> result = test->fourSum(input, 8);
	for (const auto &iter : result) {
		for (const auto &it : iter) {
			cout << it << " ";
		}
		cout << endl;
	}
	cout << endl;
	result = test->fourSum2(input, 8);
	for (const auto &iter : result) {
		for (const auto &it : iter) {
			cout << it << " ";
		}
		cout << endl;
	}
	return 0;
}
