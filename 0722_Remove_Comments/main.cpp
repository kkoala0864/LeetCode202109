#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"main() {", "/* here is commments", "  // still comments */", "   double s = 33;", "   cout << s;", "}"};
	Solution *test = new Solution();
	auto result = test->removeComments(input);
	for (const auto &iter : result) {
		cout << iter << endl;
	}
	cout << endl;
	return 0;
}
