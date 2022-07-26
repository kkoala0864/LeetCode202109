#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s = "[123,[456,[789]]]";
	Solution* test = new Solution();
	test->deserialize(s);
	return 0;
}

