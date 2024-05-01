#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> num1 = {10,2,8,7,5,6,7,10};
	vector<int> num2 = {5,8,5,3,8,4};
	Solution* test = new Solution();
	cout << test->minimumAddedInteger(num1, num2) << endl;
	return 0;
}

