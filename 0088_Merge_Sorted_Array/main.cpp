#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input1 = {1};
	vector<int> input2 = {};
	Solution* test = new Solution();
	test->merge3(input1, 1, input2, 0);
	for (const auto& iter : input1) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

