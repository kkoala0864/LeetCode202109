#include <Solution.h>

int main(void) {
	vector<string> input = {"A..","AAA","..."};
	int k = 3;
	Solution *test = new Solution();
	cout << test->ways(input, k) << endl;
	return 0;
}
