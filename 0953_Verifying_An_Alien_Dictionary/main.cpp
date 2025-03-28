#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"hello", "leetcode"};
	string order = "hlabcdefgijkmnopqrstuvwxyz";
	Solution *test = new Solution();
	cout << test->isAlienSorted(input, order) << endl;
	return 0;
}
