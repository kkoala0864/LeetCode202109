#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1("aabcc"), s2("dbbca"), s3("aadbbcbcac");
	Solution *test = new Solution();
	cout << test->isInterleave(s1, s2, s3) << endl;
	return 0;
}
