#include <Solution.h>

using std::cout;
using std::endl;

int main(void) {
	string input = ".L.R...LR..L..";
	Solution *test = new Solution();
	cout << test->pushDominoes(input) << endl;
	return 0;
}
