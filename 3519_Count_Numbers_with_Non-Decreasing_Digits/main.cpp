#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string l = "148303515506495308555489341658448750";
	string r = "15752306151363429826606076402169906057564908";
	int b = 9;
	Solution *test = new Solution();
	cout << test->countNumbers(l, r, b) << endl;
	return 0;
}
