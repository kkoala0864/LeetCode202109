#include <Solution.h>

int main(void) {
	string str = "abc";
	vector<int> shifts = {3, 5, 9};
	Solution *test = new Solution();
	cout << test->shiftingLetters(str, shifts) << endl;
	return 0;
}
