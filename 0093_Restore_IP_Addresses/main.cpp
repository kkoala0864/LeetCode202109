#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input("0279245587303");
	Solution* test = new Solution();
	vector<string> result = test->restoreIpAddresses(input);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	result = test->restoreIpAddresses2(input);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

