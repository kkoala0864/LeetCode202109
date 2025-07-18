#include <Solution.h>

int main(void) {
	vector<string> input = {"area","lead","wall","lady","ball"};
	Solution *test = new Solution();
	auto result = test->wordSquares(input);
	for (const auto& v : result) {
		for (const auto& s : v) {
			cout << s << " ";
		}
		cout << endl;
	}
	return 0;
}
