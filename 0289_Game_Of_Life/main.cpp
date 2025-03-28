#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
	Solution *test = new Solution();
	test->gameOfLife(input);
	for (const auto &iter : input) {
		for (const auto &it : iter) {
			cout << it << " ";
		}
		cout << endl;
	}
	return 0;
}
