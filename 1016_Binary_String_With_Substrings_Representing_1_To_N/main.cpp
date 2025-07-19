#include <Solution.h>

int main(void) {
	string input = "0110";
	int n = 3;
	Solution *test = new Solution();
	cout << test->queryString(input, n) << endl;
	return 0;
}
