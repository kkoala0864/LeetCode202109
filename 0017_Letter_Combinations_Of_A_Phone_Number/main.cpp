#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input("23");
	Solution* test = new Solution();
	vector<string> result = test->letterCombinations(input);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;

	cout << endl;
	result = test->letterCombinations2(input);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

