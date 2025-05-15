#include <Solution.h>

int main(void) {
	vector<vector<char>> input = {{'0','E','0','0'},{'E','0','W','E'},{'0','E','0','0'}};
	Solution *test = new Solution();
	cout << test->maxKilledEnemies(input) << endl;
	return 0;
}
