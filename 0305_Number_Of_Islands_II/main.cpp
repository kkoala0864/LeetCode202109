#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,1},{1,2},{2,1},{1,0},{0,2},{0,0},{1,1}};
	Solution* test = new Solution();
	auto result = test->numIslands2(3, 3, input);
	for (const auto& val : result) {
		cout << val << " ";
	}
	cout << endl;
	return 0;
}

