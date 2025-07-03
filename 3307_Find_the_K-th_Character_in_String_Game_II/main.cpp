#include <Solution.h>

int main(void) {
	int k = 10;
	vector<int> operations = {0,1,0,1};
	Solution *test = new Solution();
	cout << test->kthCharacter(k, operations) << endl;
	return 0;
}
