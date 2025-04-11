#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<char>> input = {{'E','E','E','E','E'},{'E','E','M','E','E'},{'E','E','E','E','E'},{'E','E','E','E','E'}};
	vector<int> click = {3, 0};
	Solution *test = new Solution();
	auto result = test->updateBoard(input, click);
	for (const auto &row : result) {
		for (const auto &cell : row) {
			cout << cell << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
