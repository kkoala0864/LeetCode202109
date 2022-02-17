#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2, 3, 5};
	Solution* test = new Solution();
	vector<vector<int>> result = test->combinationSum(input, 8);
	for (const auto iter : result) {
		for ( const auto iter2 : iter ) {
			cout << iter2 << " ";
		}
		cout << endl;
	}
	cout << endl;
	result = test->combinationSum3(input, 8);
	for (const auto iter : result) {
		for ( const auto iter2 : iter ) {
			cout << iter2 << " ";
		}
		cout << endl;
	}
	return 0;
}

