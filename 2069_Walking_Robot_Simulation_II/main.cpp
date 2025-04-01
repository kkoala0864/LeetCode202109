#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {

	//["Robot","step","step","getPos","getDir","step","getPos","getDir","getPos","getDir"]
	//[[20,13],[12],[21],[],[],[17],[],[],[],[]]


	Robot *test = new Robot(20, 13);
	test->step(12);
	test->step(21);
	auto result = test->getPos();
	cout << result[0] << " " << result[1] << endl;
	cout << test->getDir() << endl;
	test->step(17);
	result = test->getPos();
	cout << result[0] << " " << result[1] << endl;
	cout << test->getDir() << endl;
	result = test->getPos();
	cout << result[0] << " " << result[1] << endl;
	cout << test->getDir() << endl;
	return 0;
}
