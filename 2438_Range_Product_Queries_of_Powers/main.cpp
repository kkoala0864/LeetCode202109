#include <Solution.h>

int main(void) {
	int n = 919;
	vector<vector<int>> quries = {{4, 6}};
	Solution *test = new Solution();
	auto result = test->productQueries(n, quries);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
