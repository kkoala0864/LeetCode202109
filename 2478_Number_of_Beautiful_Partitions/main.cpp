#include <Solution.h>

int main(void) {
	string s = "23542185131";
	int k = 3;
	int minLength = 2;
	Solution *test = new Solution();
	cout << test->beautifulPartitions(s, k, minLength) << endl;
	return 0;
}
