#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string expression = "1/3-1/2";
	Solution *test = new Solution();
	cout << test->fractionAddition(expression) << endl;
	return 0;
}
