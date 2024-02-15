#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,1,1},{1,2,1},{0,2,1},{2,3,4},{3,4,2},{3,5,2},{4,5,2}};
	Solution* test = new Solution();
	auto result = test->findCriticalAndPseudoCriticalEdges(6, input);
	for (const auto& iter : result) {
		for (const auto& v : iter) cout << v << " ";
		cout << endl;
	}
	return 0;
}

