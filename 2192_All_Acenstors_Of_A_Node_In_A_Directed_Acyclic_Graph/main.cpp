#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,3},{5,0},{2,3},{4,3},{5,3},{1,3},{2,5},{0,1},{4,5},{4,2},{4,0},{2,1},{5,1}};
	int n = 6;
	Solution* test = new Solution();
	auto result = test->getAncestors(n, input);
	for (const auto& v : result) {
		for (const auto& v1 : v) cout << v1 << " ";
		cout << endl;
	}
	return 0;
}

