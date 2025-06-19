#include <Solution.h>

int main(void) {
	vector<int> front = {1,2,4,4,7};
	vector<int> backs = {1,3,4,1,3};
	Solution *test = new Solution();
	cout << test->flipgame(front, backs) << endl;
	return 0;
}
