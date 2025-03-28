#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<char>> input = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	string word("SEE");
	Solution *test = new Solution();
	// cout << test->exist(input, word) << endl;
	cout << test->exist2(input, word) << endl;
	return 0;
}
