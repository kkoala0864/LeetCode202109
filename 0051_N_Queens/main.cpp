#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution* test = new Solution();
	auto result = test->solveNQueens2(4);
	for (const auto& vec : result) {
		for (const auto& val : vec) {
			cout << val << endl;
		}
		cout << endl << endl;
	}
	return 0;
}

