#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
	string labels = "abaedcd";
	Solution* test = new Solution();
	auto result = test->countSubTrees(7, edges, labels);
	for (const auto& v: result) cout << v << " ";
	cout << endl;
	return 0;
}

