#include <Solution.h>

int main(void) {
	vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
	vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
	int minutes = 3;
	Solution *test = new Solution();
	cout << test->maxSatisfied(customers, grumpy, minutes) << endl;
	return 0;
}
