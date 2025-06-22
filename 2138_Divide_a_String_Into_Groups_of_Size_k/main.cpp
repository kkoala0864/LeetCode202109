#include <Solution.h>

int main(void) {
	string s = "abcdefghi";
	int k = 3;
	char fill = 'x';
	Solution *test = new Solution();
	auto result = test->divideString(s, k, fill);
	for (const auto &v : result) cout << v << " ";
	cout << endl;
	return 0;
}
