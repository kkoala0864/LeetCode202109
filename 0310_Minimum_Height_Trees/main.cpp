#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{3,0},{3,1},{3,2},{3,4},{5,4}};
	Solution* test = new Solution();
	vector<int> result = test->findMinHeightTrees(6, input);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;

}

