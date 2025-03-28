#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext");
	Solution *test = new Solution();
	cout << test->lengthLongestPath(input) << endl;
	return 0;
}
