#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<char>> input = {{' '}, {'#'}, {'o'}, {' '}, {'t'}, {'m'}, {'o'}, {' '}, {'#'}, {' '}};
	string word = "octmor";
	Solution *test = new Solution();
	cout << test->placeWordInCrossword(input, word) << endl;
	return 0;
}
