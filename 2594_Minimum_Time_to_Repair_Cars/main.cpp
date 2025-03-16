#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {4,2,3,1};
	int cars = 10;
	Solution* test = new Solution();
	cout << test->repairCars(input, cars) << endl;
	return 0;
}

