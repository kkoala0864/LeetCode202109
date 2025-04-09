#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	//["RandomizedCollection","insert","insert","remove","getRandom"]
	//[[],[1],[1],[1],[]]
	RandomizedCollection *test = new RandomizedCollection();
	cout << test->insert(1) << endl; // 1
	cout << test->insert(1) << endl; // 0
	cout << test->remove(1) << endl; // 1
	cout << test->getRandom() << endl; // 1
	return 0;
}
