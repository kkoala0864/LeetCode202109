#include <Solution.h>

int main(void) {
	int n = 2;
	vector<vector<int>> input = {{1},{2},{1,2}};
	vector<vector<int>> friends = {{1,2},{1,3},{2,3}};
	Solution *test = new Solution();
	cout << test->minimumTeachings(n, input, friends) << endl;
	return 0;
}
