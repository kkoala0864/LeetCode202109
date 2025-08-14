#include <Solution.h>

int main(void) {
	string s = "gkb";
	vector<int> order = {1,2,0};
	int k = 4;
	Solution *test = new Solution();
	cout << test->minTime(s, order, k) << endl;
	return 0;
}
