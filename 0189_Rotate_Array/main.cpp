#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,2,3,4,5};
	Solution* test = new Solution();
	test->rotate2(input, 2);
	for (const auto& iter : input) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

