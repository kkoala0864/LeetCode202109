#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"aba","bcb","ece","aa","e"};
	vector<vector<int>> queries = {{0,2},{1,4},{1,1}};
	Solution* test = new Solution();
	auto result = test->vowelStrings(input, queries);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

