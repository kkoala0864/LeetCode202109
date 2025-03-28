#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	Solution *test = new Solution();
	auto result = test->transpose(input);
	for (const auto &vec : result) {
		for (const auto &val : vec) {
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}
