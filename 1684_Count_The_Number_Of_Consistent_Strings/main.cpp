#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string allow = "ab";
	vector<string> words = {"ad", "bd", "aaab", "baa", "badab"};
	Solution *test = new Solution();
	cout << test->countConsistentStrings(allow, words) << endl;
	return 0;
}
