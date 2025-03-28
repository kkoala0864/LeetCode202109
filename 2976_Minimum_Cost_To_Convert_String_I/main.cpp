#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string source = "abcd";
	string target = "acbe";
	vector<char> original = {'a', 'b', 'c', 'c', 'e', 'd'};
	vector<char> changed = {'b', 'c', 'b', 'e', 'b', 'e'};
	vector<int> cost = {2, 5, 5, 1, 2, 20};
	Solution *test = new Solution();
	cout << test->minimumCost(source, target, original, changed, cost) << endl;
	return 0;
}
