#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"a", "b", "c", "ab", "ac", "aa"};
	Solution *test = new Solution();
	vector<vector<int>> result = test->palindromePairs2(input);
	for (const auto &iter : result) {
		cout << "[" << iter[0] << " : " << iter[1] << "]" << endl;
	}
	cout << endl;
	result = test->palindromePairs3(input);
	for (const auto &iter : result) {
		cout << "[" << iter[0] << " : " << iter[1] << "]" << endl;
	}
	return 0;
}
