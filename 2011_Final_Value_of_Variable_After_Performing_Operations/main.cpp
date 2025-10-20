#include <Solution.h>

int main(void) {
	vector<string> input = {"--X","X++","X++"};
	Solution *test = new Solution();
	cout << test->finalValueAfterOperations(input) << endl;
	return 0;
}
