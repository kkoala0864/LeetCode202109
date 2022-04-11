#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1},{2},{3},{4},{7},{6},{5}};
	Solution* test = new Solution();
	auto result = test->shiftGrid(input, 2);
	for (const auto& out : result) {
		for (const auto iner :  out) {
			cout << iner << " ";
		}
		cout << endl;
	}
	return 0;
}

