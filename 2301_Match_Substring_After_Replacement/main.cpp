#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "awcb";
	string sub = "awd";
	vector<vector<char>> mappings = {{'a','w'},{'w','c'},{'d','b'}};
	Solution *test = new Solution();
	cout << test->matchReplacement(input, sub, mappings) << endl;
	return 0;
}
