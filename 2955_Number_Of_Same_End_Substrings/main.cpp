#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s = "abcaab";
	vector<vector<int>> input = {{0,0},{1,4},{2,5},{0,5}};
	Solution* test = new Solution();
	auto result = test->sameEndSubstringCount(s, input);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

