#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"gin", "zen", "gig", "msg"};
	Solution *test = new Solution();
	cout << test->uniqueMorseRepresentations(input) << endl;
	return 0;
}
