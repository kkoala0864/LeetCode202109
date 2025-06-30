#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{3,4,5},{4,5,6}};
	vector<int> target = {3,2,5};
	Solution *test = new Solution();
	cout << test->mergeTriplets(input, target) << endl;
	return 0;
}
