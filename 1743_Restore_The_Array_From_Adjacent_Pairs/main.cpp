#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{4,-2},{1,4},{-3,1}};
	Solution* test = new Solution();
	auto result = test->restoreArray(input);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}

