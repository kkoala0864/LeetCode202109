#include <Solution.h>

int main(void) {
	vector<int> b1 = {84,80,43,8,80,88,43,14,100,88};
	vector<int> b2 = {32,32,42,68,68,100,42,84,14,8};
	Solution *test = new Solution();
	cout << test->minCost(b1, b2) << endl;
	return 0;
}
