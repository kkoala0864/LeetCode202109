#include <Solution.h>

int main(void) {
	vector<string> input = {"aabbcc", "aabbcc","c","e","aabbcd"};
	Solution *test = new Solution();
	cout << test->findLUSlength(input) << endl;
	return 0;
}
