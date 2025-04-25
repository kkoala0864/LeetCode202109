#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{2,3},{2,5},{1,8},{20,25}};
	vector<int> queries = {2,19,5,22};
	Solution *test = new Solution();
	auto result = test->minInterval(input, queries);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
