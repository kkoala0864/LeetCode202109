#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "baababbaabbaaabaabbabbbabaaaaaabaabababaaababbb";
	Solution *test = new Solution();
	cout << test->minimumDeletions(input) << endl;
	return 0;
}
