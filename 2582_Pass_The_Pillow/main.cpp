#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 4;
	int time = 5;
	Solution *test = new Solution();
	cout << test->passThePillow(n, time) << endl;
	return 0;
}
