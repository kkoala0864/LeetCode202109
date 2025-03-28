#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
	Solution *test = new Solution();
	auto result = test->findSmallestSetOfVertices(6, input);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	result = test->findSmallestSetOfVertices2(6, input);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
