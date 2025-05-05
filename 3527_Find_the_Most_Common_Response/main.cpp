#include <Solution.h>

int main(void) {
	vector<vector<string>> input = {{"good","ok","good","ok"},{"ok","bad","good","ok","ok"},{"good"},{"bad"}};
	Solution *test = new Solution();
	cout << test->findCommonResponse(input) << endl;
	return 0;
}
