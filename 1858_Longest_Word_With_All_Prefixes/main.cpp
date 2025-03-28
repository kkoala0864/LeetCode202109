#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"x", "y", "l", "k", "w", "b", "f", "z", "t", "n", "j", "r", "q", "a", "h", "v", "g", "m", "u", "o", "p", "d", "i", "c", "s", "e"};
	Solution *test = new Solution();
	cout << test->longestWord(input) << endl;
	return 0;
}
