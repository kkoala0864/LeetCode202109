#include <Solution.h>

using std::cout;
using std::endl;

int main(void) {
	string input = "aaa";
	Solution *test = new Solution();
	cout << test->addMinimum(input) << endl;
	return 0;
}
