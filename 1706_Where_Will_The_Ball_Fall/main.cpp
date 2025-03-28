#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1, 1, 1, 1, 1, 1}, {-1, -1, -1, -1, -1, -1}, {1, 1, 1, 1, 1, 1}, {-1, -1, -1, -1, -1, -1}};
	Solution *test = new Solution();
	auto result = test->findBall(input);
	for (const auto &v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
