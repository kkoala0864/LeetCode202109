#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> red = {{0,1}};
	vector<vector<int>> blue = {{2,1}};

	Solution* test = new Solution();
	auto result = test->shortestAlternatingPaths(3, red, blue);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}

