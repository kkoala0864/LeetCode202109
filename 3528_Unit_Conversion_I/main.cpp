#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{0,1,2},{1,2,3}};
	Solution *test = new Solution();
	auto result = test->baseUnitConversions(input);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
