#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3, 4, 1, 2, 6};
	vector<vector<int>> queries = {{0, 4}};
	Solution *test = new Solution();
	auto result = test->isArraySpecial(input, queries);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
