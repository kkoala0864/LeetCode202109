#include <Solution.h>

int main(void) {
	Solution *test = new Solution();
	int numerator = 1;
	int denominator = -1;
	cout << test->fractionToDecimal(numerator, denominator) << endl;
	return 0;
}
