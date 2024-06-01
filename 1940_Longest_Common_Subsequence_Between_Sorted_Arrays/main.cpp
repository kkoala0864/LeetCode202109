#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,3,4},{1,4,7,9}};
	Solution* test = new Solution();
	auto result = test->longestCommonSubsequence(input);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}

