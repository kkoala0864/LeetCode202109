#include <Solution.h>

int main(void) {
	int maxChoosableInteger = 4;
	int desiredTotal = 6;
	Solution *test = new Solution();
	cout << test->canIWin(maxChoosableInteger, desiredTotal) << endl;
	return 0;
}
