#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,0,1},{1,0,0},{0,0,0}};
	Solution* test = new Solution();
	auto result = test->highestPeak(input);
	for (const auto& r : result) {
		for (const auto& c : r) cout << c << " ";
		cout << endl;
	}
	return 0;
}

