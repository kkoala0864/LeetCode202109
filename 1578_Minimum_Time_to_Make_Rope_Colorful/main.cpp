#include <Solution.h>

int main(void) {
	string input = "abaac";
	vector<int> nt = {1,2,3,4,5};
	Solution *test = new Solution();
	cout << test->minCost(input, nt) << endl;
	return 0;
}
