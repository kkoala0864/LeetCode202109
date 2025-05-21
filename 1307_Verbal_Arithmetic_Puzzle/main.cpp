#include <Solution.h>

int main(void) {
	vector<string> words = {"CBA","CBA","CBA","CBA","CBA"};
	string result = "EDD";
	Solution *test = new Solution();
	cout << test->isSolvable(words, result) << endl;
	return 0;
}
