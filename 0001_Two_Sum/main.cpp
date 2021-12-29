#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,2,4};
	Solution* test = new Solution();
	vector<int> result = test->twoSum(input, 6);
	for (const auto iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	result = test->twoSum2(input, 6);
	for (const auto iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

