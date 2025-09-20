#include <Solution.h>

int main(void) {
	//["Router","addPacket","getCount","forwardPacket","getCount","addPacket","getCount"]
	//[[5],[4,2,1],[2,1,1],[],[2,1,1],[4,2,1],[2,1,1]]
	Router* test = new Router(5);
	cout << test->addPacket(4, 2, 1) << endl;
	cout << test->getCount(2, 1, 1) << endl;
	auto result = test->forwardPacket();
	for (const auto& r : result) cout << r << " ";
	cout << endl;
	cout << test->getCount(2, 1, 1) << endl;
	cout << test->addPacket(4, 2, 1) << endl;
	cout << test->getCount(2, 1, 1) << endl;
	return 0;
}
