#include <Solution.h>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<char>> input = {{'a'}};
	string pattern = "a";
	Solution *test = new Solution();
	cout << test->countCells(input, pattern) << endl;
	return 0;
}
