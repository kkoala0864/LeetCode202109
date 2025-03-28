#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "dsahjpjauf";
	vector<string> vec = {"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"};
	Solution *test = new Solution();
	cout << test->numMatchingSubseq(input, vec) << endl;
	cout << test->numMatchingSubseq2(input, vec) << endl;
	return 0;
}
