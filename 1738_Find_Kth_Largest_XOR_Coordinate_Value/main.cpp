#include <Solution.h>

int main(void) {
	vector<vector<int>> matrix = {{10,9,5},{2,0,4},{1,0,9},{3,4,8}};
	int k = 10;
	Solution *test = new Solution();
	cout << test->kthLargestValue(matrix, k) << endl;
	return 0;
}
