#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	uint32_t i = 4294967293;
	Solution* test = new Solution();
	cout << test->reverseBits(i) << endl;
	cout << test->reverseBits2(i) << endl;
	return 0;
}

