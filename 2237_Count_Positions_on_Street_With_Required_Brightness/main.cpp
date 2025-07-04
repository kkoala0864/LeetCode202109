#include <Solution.h>

int main(void) {
	int n = 5;
	vector<vector<int>> lights = {{0,1},{2,1},{3,2}};
	vector<int> requirement = {0,2,1,4,1};
	Solution *test = new Solution();
	cout << test->meetRequirement(n, lights, requirement) << endl;
	return 0;
}
