#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,0}};
	Solution* test = new Solution();
	vector<int> result = test->findOrder(2, input);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	result = test->findOrder3(2, input);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

