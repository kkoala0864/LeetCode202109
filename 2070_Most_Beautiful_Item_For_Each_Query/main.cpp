#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}};
	vector<int> i2 = {1, 2, 3, 4, 5, 6};
	Solution *test = new Solution();
	auto result = test->maximumBeauty(input, i2);
	for (const auto &v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
