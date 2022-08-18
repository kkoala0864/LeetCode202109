#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	Solution* test = new Solution();
	vector<int> result = test->spiralOrder(input);
	for (const auto iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	result = test->spiralOrder2(input);
	for (const auto iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	result = test->spiralOrder3(input);
	for (const auto iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

