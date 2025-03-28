#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 3, 4, 8, 7, 9, 3, 5, 1};
	Solution *test = new Solution();
	auto result = test->divideArray(input, 2);
	for (const auto &v : result) {
		for (const auto &e : v) {
			cout << e << " ";
		}
		cout << endl;
	}
	return 0;
}
