#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input("9,3,4,#,#,1,#,#,2,#,6,#,#");
	Solution *test = new Solution();
	cout << test->isValidSerialization(input) << endl;
	cout << test->isValidSerialization2(input) << endl;
	return 0;
}
