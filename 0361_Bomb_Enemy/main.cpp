#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<char>> input = {{'E'},{'E'},{'E'}};
	Solution* test = new Solution();
	cout << test->maxKilledEnemies(input) << endl;
	return 0;
}

