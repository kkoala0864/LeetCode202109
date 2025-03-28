#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0, 0}, {0, 1}, {1, 2}, {2, 1}};
	auto input2 = input;
	Solution *test = new Solution();
	auto result = test->numIslands2(3, 3, input);
	for (const auto &val : result) {
		cout << val << " ";
	}
	cout << endl;
	result = test->numIslands22(3, 3, input2);
	for (const auto &val : result) {
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
