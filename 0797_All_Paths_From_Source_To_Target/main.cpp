#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,2},{3},{3},{}};
	Solution* test = new Solution();
	auto result = test->allPathsSourceTarget(input);
	for (const auto& l1 : result) {
		for (const auto& l2 : l1) cout << l2 << " ";
		cout << endl;
	}
	cout << endl;
	result = test->allPathsSourceTarget2(input);
	for (const auto& l1 : result) {
		for (const auto& l2 : l1) cout << l2 << " ";
		cout << endl;
	}
	return 0;
}

