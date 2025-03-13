#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<char>> input = {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
	Solution* test = new Solution();
	cout << test->countBattleships(input) << endl;
	return 0;
}

