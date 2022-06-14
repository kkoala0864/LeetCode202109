#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string w1("a"), w2("ab");
	Solution* test = new Solution();
	cout << test->minDistance(w1, w2) << endl;
	return 0;
}

