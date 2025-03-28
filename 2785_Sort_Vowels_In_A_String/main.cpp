#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "lEetcOde";
	Solution *test = new Solution();
	cout << test->sortVowels(input) << endl;
	return 0;
}
