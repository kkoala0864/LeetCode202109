#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input("Aabb");
	Solution* test = new Solution();
	cout << test->frequencySort(input) << endl;
	return 0;
}

