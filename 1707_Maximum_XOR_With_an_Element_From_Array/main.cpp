#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {5,2,4,6,6,3};
	vector<vector<int>> queries = {{12,4},{8,1},{6,3}};
	Solution *test = new Solution();
	auto result = test->maximizeXor(input, queries);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
