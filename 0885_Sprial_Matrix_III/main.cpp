#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution* test = new Solution();
	auto result = test->spiralMatrixIII(5, 6, 1, 4);
	for (const auto& v : result) {
		for (const auto& c : v) {
			cout << c << " ";
		}
		cout << endl;
	}
	return 0;
}

