#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{-16,15},{-7,-18},{-4,2},{1,0},{7,10},{9,-6},{14,5},{15,13},{16,-12},{20,20}};
	int k = 8;
	Solution *test = new Solution();
	cout << test->findMaxValueOfEquation(input, k) << endl;
	return 0;
}
