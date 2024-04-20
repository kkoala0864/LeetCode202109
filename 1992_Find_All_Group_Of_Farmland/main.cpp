#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,0,0},{0,1,1},{0,1,1}};
	Solution* test = new Solution();
	vector<vector<int>> result = test->findFarmland(input);
	for (const auto& r : result) {
		for (const auto& v : r) cout << v << " ";
		cout << endl;
	}
	return 0;
}

