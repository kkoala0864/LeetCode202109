#include <Solution.h>

int main(void) {
	string input = "NSWWEW";
	int k = 3;
	Solution *test = new Solution();
	cout << test->maxDistance(input, k) << endl;
	return 0;
}
