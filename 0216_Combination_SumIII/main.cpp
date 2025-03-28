#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution *test = new Solution();
	auto result = test->combinationSum3(3, 9);
	for (const auto &vec : result) {
		for (const auto &val : vec) {
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}
