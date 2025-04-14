#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,0,1,1,9,7};
	int a = 7;
	int b = 2;
	int c = 3;
	Solution *test = new Solution();
	cout << test->countGoodTriplets(input, a, b, c) << endl;
	return 0;
}
