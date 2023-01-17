#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1 = "parker";
	string s2 = "morris";
	string base = "parser";
	Solution* test = new Solution();
	cout << test->smallestEquivalentString(s1, s2, base) << endl;
	return 0;
}

