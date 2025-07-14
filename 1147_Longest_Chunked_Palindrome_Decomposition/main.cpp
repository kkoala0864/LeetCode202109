#include <Solution.h>

int main(void) {
	string input = "elvtoelvto";
	Solution *test = new Solution();
	cout << test->longestDecomposition(input) << endl;
	return 0;
}
