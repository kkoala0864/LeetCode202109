#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{7, 9}, {4, 5}, {7, 9}, {-7, -1}, {0, 10}, {3, 10}, {3, 6}, {2, 3}};
	Solution *test = new Solution();
	cout << test->findLongestChain(input) << endl;
	return 0;
}
