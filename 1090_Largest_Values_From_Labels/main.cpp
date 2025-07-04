#include <Solution.h>

int main(void) {
	vector<int> values = {5,4,3,2,1};
	vector<int> labels = {1,1,2,2,3};
	int numWanted = 3;
	int useLimit = 1;
	Solution *test = new Solution();
	cout << test->largestValsFromLabels(values, labels, numWanted, useLimit) << endl;
	return 0;
}
