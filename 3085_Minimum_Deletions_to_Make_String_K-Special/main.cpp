#include <Solution.h>

int main(void) {
	string input = "yynaayyyy";
	int k = 1;
	Solution *test = new Solution();
	cout << test->minimumDeletions(input, k) << endl;
	return 0;
}
