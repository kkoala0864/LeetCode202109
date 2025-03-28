#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"abcd", "bnrt", "crmy", "dtye"};
	Solution *test = new Solution();
	cout << test->validWordSquare(input) << endl;
	return 0;
}
