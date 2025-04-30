#include <Solution.h>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {12,345,2,6,7896};
	Solution *test = new Solution();
	cout << test->findNumbers(input) << endl;
	return 0;
}
