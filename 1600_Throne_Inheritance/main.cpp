#include <Solution.h>

int main(void) {
	//["ThroneInheritance", "birth", "birth", "birth", "birth", "birth", "birth", "getInheritanceOrder", "death", "getInheritanceOrder"]
	//[["king"], ["king", "andy"], ["king", "bob"], ["king", "catherine"], ["andy", "matthew"], ["bob", "alex"], ["bob", "asha"], [null], ["bob"], [null]]

	ThroneInheritance *test = new ThroneInheritance("king");
	test->birth("king", "andy");
	test->birth("king", "bob");
	test->birth("king", "catherine");
	test->birth("andy", "matthew");
	test->birth("bob", "alex");
	test->birth("bob", "asha");
	auto result = test->getInheritanceOrder();
	for (auto &name : result) {
		cout << name << " ";
	}
	cout << endl;
	test->death("bob");
	result = test->getInheritanceOrder();
	for (auto &name : result) {
		cout << name << " ";
	}
	cout << endl;
	return 0;

}
