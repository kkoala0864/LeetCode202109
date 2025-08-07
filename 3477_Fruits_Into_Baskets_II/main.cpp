#include <Solution.h>

int main(void) {
	vector<int> fruits = {4,2,5};
	vector<int> basket = {3,5,4};
	Solution *test = new Solution();
	cout << test->numOfUnplacedFruits(fruits, basket) << endl;
	return 0;
}
