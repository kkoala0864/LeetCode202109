#include <Solution.h>

int main(void) {
	string input = "948635";
	int k = 64;
	Solution *test = new Solution();
	cout << test->getMinSwaps(input, k) << endl;
	return 0;
}
