#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> fruits = {41,43,94};
	vector<int> baskets = {39,10,47};
	Solution* test = new Solution();
	cout << test->numOfUnplacedFruits(fruits, baskets) << endl;
	return 0;
}

