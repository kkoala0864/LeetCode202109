#include <Solution.h>

int main(void) {
	int n = 3;
	vector<vector<int>> queries = {{5,3},{4,7},{2,3}};
	Solution *test = new Solution();
	auto result = test->cycleLengthQueries(n, queries);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
