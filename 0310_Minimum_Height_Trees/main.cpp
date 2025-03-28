#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1, 0}, {1, 2}, {1, 3}};
	Solution *test = new Solution();
	vector<int> result = test->findMinHeightTrees(4, input);
	for (const auto &iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	result = test->findMinHeightTrees3(4, input);
	for (const auto &iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}
