#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "zzzzz";
	Solution *test = new Solution();
	cout << test->countHomogenous(input) << endl;
	return 0;
}
