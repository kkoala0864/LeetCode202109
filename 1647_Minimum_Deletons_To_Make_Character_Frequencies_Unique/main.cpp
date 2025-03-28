#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "odofingjfdncnecmfdekekchbbicbflkoanohamkcjljbfmahhbnkiangdal";
	Solution *test = new Solution();
	cout << test->minDeletions(input) << endl;
	return 0;
}
