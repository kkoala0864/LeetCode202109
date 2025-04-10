#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	long long start = 15;
	long long finish = 215;
	int limit = 6;
	string s = "10";
	Solution *test = new Solution();
	cout << test->numberOfPowerfulInt(start, finish, limit, s) << endl;
	return 0;
}
