#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"bbabbaa","aaaaaa","aaabab","baaabba","bbbaabbbabaab","abbabaaabbbabaaabbbb","ababbba"};
	Solution* test = new Solution();
	cout << test->shortestSuperstring(input) << endl;
	cout << "aaaaaababbbabbaaabbabaaabbbabaaabbbbaabbbabaab" << endl;
	return 0;
}

