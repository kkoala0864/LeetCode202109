#include <Solution.h>

int main(void) {
	vector<vector<int>> offers = {{0,0,6},{1,2,8},{0,3,7},{2,2,5},{0,1,5},{2,3,2},{0,2,8},{2,3,10},{0,3,2}};
	int n = 4;
	Solution *test = new Solution();
	cout << test->maximizeTheProfit(n, offers) << endl;
	return 0;
}
