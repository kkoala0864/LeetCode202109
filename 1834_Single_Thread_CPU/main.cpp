#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
	Solution *test = new Solution();
	auto result = test->getOrder(input);
	for (const auto &r : result)
		cout << r << " ";
	cout << endl;
	return 0;
}
