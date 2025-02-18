#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "gaixgqpgdrhhxuurgrriwovkbjjbffnlnjcnyzbmblymcmvnftlpaiqepgxgiperurhgduaqpqxqgaxdexur";
	int k = 6;
	Solution* test = new Solution();
	cout << test->maxSubstringLength(input, k) << endl;
	return 0;
}

