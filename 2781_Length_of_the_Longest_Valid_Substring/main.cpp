#include <Solution.h>

using std::cout;
using std::endl;

int main(void) {
	string input = "cbaaaabc";
	vector<string> forbidden = {"aaa","cb"};
	Solution *test = new Solution();
	cout << test->longestValidSubstring(input, forbidden) << endl;
	return 0;
}
