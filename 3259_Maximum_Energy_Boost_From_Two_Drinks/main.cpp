#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> inputA = {1, 3, 1};
	vector<int> inputB = {3, 1, 1};
	Solution *test = new Solution();
	cout << test->maxEnergyBoost(inputA, inputB) << endl;
	return 0;
}
