#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{1,0},{2,0},{3,0},{2,2},{3,2}};
	Solution *test = new Solution();
	cout << test->countTrapezoids(input) << endl;
	return 0;
}
