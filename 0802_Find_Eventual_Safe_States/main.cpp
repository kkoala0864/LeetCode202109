#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,2},{2,3},{5},{0},{5},{},{}};
	Solution* test = new Solution();
	auto result = test->eventualSafeNodes2(input);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

