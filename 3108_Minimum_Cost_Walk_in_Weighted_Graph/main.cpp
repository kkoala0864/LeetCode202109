#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 5;
	vector<vector<int>> edge = {{0,1,7},{1,3,7},{1,2,1}};
	vector<vector<int>> query = {{0,3},{3,4}};
	Solution* test = new Solution();
	auto result = test->minimumCost(n, edge, query);
	for (const auto& iter : result) cout << iter << " ";
	cout << endl;
	return 0;
}

