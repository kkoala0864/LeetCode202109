#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "pqrstuvwxyzabcdefghijklmno";
	string keyword = "leetcode";
	Solution* test = new Solution();
	cout << test->calculateTime(input, keyword) << endl;
	cout << test->calculateTime2(input, keyword) << endl;
	return 0;
}

