#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"qo","fo","fq","qf","fo","ff","qq","qf","of","of","oo","of","of","qf","qf","of"};
	Solution* test = new Solution();
	cout << test->longestPalindrome(input) << endl;
	return 0;
}

