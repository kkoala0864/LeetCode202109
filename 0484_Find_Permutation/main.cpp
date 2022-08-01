#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "DDIIDI";
	Solution* test = new Solution();
	vector<int> result = test->findPermutation(input);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	result = test->findPermutation2(input);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

