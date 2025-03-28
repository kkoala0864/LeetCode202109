#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 2, 1, 1, 0};
	Solution *test = new Solution();
	auto result = test->applyOperations(input);
	for (const auto &e : result) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
