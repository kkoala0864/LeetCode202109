#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,1,1},{1,0,1},{1,1,1}};
	Solution* test = new Solution();
	test->setZeroes2(input);
	for (const auto iter : input) {
		for (const auto iter2 : iter) {
			cout << iter2 << "  ";
		}
		cout << endl;
	}
	return 0;
}

