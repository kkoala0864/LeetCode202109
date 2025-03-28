#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"pay", "attention", "practice", "attend"};
	string pref = "at";
	Solution *test = new Solution();
	cout << test->prefixCount(input, pref) << endl;
	return 0;
}
