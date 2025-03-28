#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<char>> input = {{'*', '#', '*', '.', '.', '.', '#', '.', '*', '.'}};
	Solution *test = new Solution();
	auto result = test->rotateTheBox(input);
	for (const auto &v : result) {
		for (const auto &c : v) {
			cout << c << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
