#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "epmxqygtpncdtrcqghurhexfxehruhgqcrtdcnptgyqxmpeivgditbwbgmnvvnmgbwbtidgvinmoomn";
	Solution *test = new Solution();
	cout << test->maxProduct(input) << endl;
	return 0;
}
