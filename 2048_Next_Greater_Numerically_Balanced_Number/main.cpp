#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution *test = new Solution();
	cout << test->nextBeautifulNumber(3000) << endl;
	cout << test->nextBeautifulNumber2(3000) << endl;
	return 0;
}
