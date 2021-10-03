#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
	Solution* test = new Solution();
	vector<vector<int>> result = test->pacificAtlantic(input);
	for (const auto& outer : result) {
		for (const auto& inter : outer) {
			cout << inter << " ";
		}
		cout << endl;
	}
	return 0;
}

