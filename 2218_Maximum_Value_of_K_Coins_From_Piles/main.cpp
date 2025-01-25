#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{37,88},{51,64},{9,62}};
	int k = 2;
	Solution* test = new Solution();
	cout << test->maxValueOfCoins(input, k) << endl;
	return 0;
}

