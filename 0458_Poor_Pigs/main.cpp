#include <Solution.h>

int main(void) {
	int buckets = 4;
	int minutesToDie = 15;
	int minutesToTest = 15;
	Solution *test = new Solution();
	cout << test->poorPigs(buckets, minutesToDie, minutesToTest) << endl;
	return 0;
}
