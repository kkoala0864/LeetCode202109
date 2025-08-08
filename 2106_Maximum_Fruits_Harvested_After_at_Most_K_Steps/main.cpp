#include <Solution.h>

int main(void) {
	vector<vector<int>> fruits = {{0,10000}};
	int startPos = 200000, k = 200000;
	Solution *test = new Solution();
	cout << test->maxTotalFruits(fruits, startPos, k) << endl;
	return 0;
}
