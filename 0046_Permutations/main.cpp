#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 3};
	Solution *test = new Solution();
	vector<vector<int>> result = test->permute(input);
	for (const auto &iter : result) {
		for (const auto &iter2 : iter) {
			cout << iter2 << " ";
		}
		cout << endl;
	}
	cout << endl;
	result = test->permute(input);
	for (const auto &iter : result) {
		for (const auto &iter2 : iter) {
			cout << iter2 << " ";
		}
		cout << endl;
	}
	return 0;
}
