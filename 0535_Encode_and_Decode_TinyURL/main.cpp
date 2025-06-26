#include <Solution.h>

int main(void) {
	string s = "https://leetcode.com/problems/design-tinyurl";
	Solution *test = new Solution();
	string ss = test->encode(s);
	cout << "Encoded: " << ss << endl;
	string t = test->decode(ss);
	cout << "Decoded: " << t << endl;
	return 0;
}
