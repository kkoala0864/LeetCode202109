#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,10,3,3,3};
	int k = 3;
	Solution* test = new Solution();
	cout << test->maxKelements(input, k) << endl;
	return 0;
}

