#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 3};
	Solution *test = new Solution();
	vector<vector<int>> result = test->subsets(input);
	for (const auto &vec : result) {
		for (const auto &iter : vec) {
			cout << iter << " ";
		}
		cout << endl;
	}
	result = test->subsets2(input);
	for (const auto &vec : result) {
		for (const auto &iter : vec) {
			cout << iter << " ";
		}
		cout << endl;
	}
	result = test->subsets3(input);
	for (const auto &vec : result) {
		for (const auto &iter : vec) {
			cout << iter << " ";
		}
		cout << endl;
	}
	return 0;
}
