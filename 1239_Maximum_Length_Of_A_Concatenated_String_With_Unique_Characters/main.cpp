#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"jnfbyktlrqumowxd", "mvhgcpxnjzrdei"};
	Solution *test = new Solution();
	cout << test->maxLength(input) << endl;
	cout << test->maxLength2(input) << endl;
	return 0;
}
