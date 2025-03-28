#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{2, 3}, {1, 3}, {5, 4}, {6, 4}};
	Solution *test = new Solution();
	auto result = test->findWinners(input);
	for (const auto &v : result) {
		for (const auto &c : v)
			cout << c << " ";
		cout << endl;
	}
	cout << endl;
	result = test->findWinners2(input);
	for (const auto &v : result) {
		for (const auto &c : v)
			cout << c << " ";
		cout << endl;
	}
	cout << endl;
	return 0;
}
