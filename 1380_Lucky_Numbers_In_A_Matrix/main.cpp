#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1, 10, 4, 2}, {9, 3, 8, 7}, {15, 16, 17, 12}};
	Solution *test = new Solution();
	auto result = test->luckyNumbers(input);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
