#include <Solution.h>

int main(void) {
	string input = "azbk";
	int t = 1;
	Solution *test = new Solution();
	cout << test->lengthAfterTransformations(input, t) << endl;
	return 0;
}
