#include <Solution.h>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<char>> input = {{'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'}};
	Solution *test = new Solution();
	cout << test->containsCycle(input) << endl;
	return 0;
}
