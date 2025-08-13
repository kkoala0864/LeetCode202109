#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	int x = 1, y = 0, k = 3;
	Solution *test = new Solution();
	auto result = test->reverseSubmatrix(input, x, y, k);
	for (const auto& r : result) {
		for (const auto& v : r) cout << v << " ";
		cout << endl;
	}
	return 0;
}
