#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 3;
	Solution *test = new Solution();
	auto result = test->constructDistancedSequence(n);
	for (const auto &v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
