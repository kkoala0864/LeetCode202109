#include <Solution.h>

int main(void) {
	string s = "leet";
	string t = "code";
	vector<int> nextCost = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	vector<int> prevCost = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	Solution *test = new Solution();
	cout << test->shiftDistance(s, t, nextCost, prevCost) << endl;
	return 0;
}
