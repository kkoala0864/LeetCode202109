#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> seat = {3,1,5};
	vector<int> student = {2,7,4};
	Solution* test = new Solution();
	cout << test->minMovesToSeat(seat, student) << endl;
	return 0;
}

