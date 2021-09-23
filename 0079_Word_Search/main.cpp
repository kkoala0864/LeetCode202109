#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<char>> input = {{'a', 'a'}};
	string word("aaa");
	Solution* test = new Solution();
	cout << test->exist(input, word) << endl;
	return 0;
}

