#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"wrt","wrf","er","ett","rftt"};
	Solution* test = new Solution();
	cout << test->alienOrder(input) << endl;
	cout << test->alienOrder2(input) << endl;
	return 0;
}

