#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {5, 3, 4, 1, 3, 2};
	Solution *test = new Solution();
	auto result = test->minCosts(input);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
