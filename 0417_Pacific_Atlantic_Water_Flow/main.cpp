#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,1,1},{1,1,1},{1,1,1}};
	Solution* test = new Solution();
	vector<vector<int>> result = test->pacificAtlantic(input);
	for (const auto& outer : result) {
		for (const auto& inter : outer) {
			cout << inter << " ";
		}
		cout << endl;
	}
	cout << endl;
	vector<vector<int>> result2 = test->pacificAtlantic2(input);
	for (const auto& outer : result2) {
		for (const auto& inter : outer) {
			cout << inter << " ";
		}
		cout << endl;
	}
	return 0;
}

