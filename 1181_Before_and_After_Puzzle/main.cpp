#include <Solution.h>

int main(void) {
	vector<string> input = {"mission statement",
		"a quick bite to eat",
		"a chip off the old block",
		"chocolate bar",
		"mission impossible",
		"a man on a mission",
		"block party",
		"eat my words",
		"bar of soap"};
	Solution *test = new Solution();
	auto result = test->beforeAndAfterPuzzles(input);
	for (const auto &s : result) {
		cout << s << endl;
	}
	return 0;
}
