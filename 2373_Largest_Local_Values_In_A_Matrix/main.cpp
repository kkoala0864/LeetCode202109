#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}};
	Solution* test = new Solution();
	auto result = test->largestLocal(input);
	for (const auto& v : result) {
		for (const auto& c : v) cout << c << " ";
		cout << endl;
	}
	return 0;
}

