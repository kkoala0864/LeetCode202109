#include <Solution.h>

int main(void) {
	string input = "111010110";
	vector<vector<int>> queries = {{3,3}};
	Solution *test = new Solution();
	auto result = test->substringXorQueries(input, queries);
	for (const auto& v : result) {
		cout << "[" << v[0] << "," << v[1] << "]" << endl;
	}
	return 0;
}
