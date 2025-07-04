#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{2,5},{8,4},{0,-1}};
	Solution *test = new Solution();
	auto result = test->findDiagonalOrder(input);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
