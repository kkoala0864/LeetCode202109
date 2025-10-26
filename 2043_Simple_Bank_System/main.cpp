#include <Solution.h>

int main(void) {
	//["Bank", "withdraw", "transfer", "deposit", "transfer", "withdraw"]
	//[[[10, 100, 20, 50, 30]], [3, 10], [5, 1, 20], [5, 20], [3, 4, 15], [10, 50]]
	vector<long long> input = {10, 100, 20, 50, 30};
	Bank *test = new Bank(input);
	cout << test->withdraw(3, 10) << endl;
	cout << test->transfer(5, 1, 20) << endl;
	cout << test->deposit(5, 20) << endl;
	cout << test->transfer(3, 4, 15) << endl;
	cout << test->withdraw(10, 50) << endl;
	return 0;
}
