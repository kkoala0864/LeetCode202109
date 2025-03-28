#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string secret("1807");
	Solution *test = new Solution();
	cout << test->getHint(secret, "7810") << endl;
	cout << test->getHint2(secret, "7810") << endl;
	cout << test->getHint3(secret, "7810") << endl;
	return 0;
}
