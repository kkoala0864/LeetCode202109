#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input("aab");
	Solution* test = new Solution();
	vector<vector<string>> result = test->partition(input);
	for (const auto& iter : result) {
		for (const auto& it : iter) {
			cout << it << " ";
		}
		cout << endl;
	}
	vector<vector<string>> result2 = test->partition2(input);
	for (const auto& iter : result2) {
		for (const auto& it : iter) {
			cout << it << " ";
		}
		cout << endl;
	}
	return 0;
}

