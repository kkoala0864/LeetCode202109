#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution* test = new Solution();
	vector<vector<int>> input = {{1,4},{2,5},{1,3},{3,4}};
	int limit = 4;
	auto result = test->queryResults(limit, input);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}

