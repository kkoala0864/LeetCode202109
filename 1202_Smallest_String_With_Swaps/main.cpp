#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,1},{1,2}};
	string str = "cba";
	Solution* test = new Solution();
	cout << test->smallestStringWithSwaps(str, input) << endl;
	return 0;
}

