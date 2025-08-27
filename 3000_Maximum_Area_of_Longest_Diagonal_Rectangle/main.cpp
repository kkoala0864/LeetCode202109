#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{6,5},{8,6},{2,10},{8,1},{9,2},{3,5},{3,5}};
	Solution *test = new Solution();
	cout << test->areaOfMaxDiagonal(input) << endl;
	return 0;
}
