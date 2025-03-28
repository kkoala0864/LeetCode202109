#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> quality = {25, 68, 35, 62, 52, 57, 35, 83, 40, 51};
	vector<int> wage = {147, 97, 251, 129, 438, 443, 120, 366, 362, 343};
	Solution *test = new Solution();
	cout << test->mincostToHireWorkers(quality, wage, 6) << endl;
	return 0;
}
