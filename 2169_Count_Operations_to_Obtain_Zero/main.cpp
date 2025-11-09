#include <Solution.h>

int main(void) {
        int num1 = 2;
        int num2 = 3;
	Solution *test = new Solution();
        cout << test->countOperations(num1, num2) << endl;
	return 0;
}
