#include <Solution.h>

int main(void) {
	// ["FileSystem","createPath","createPath","get","createPath","get"]
	// [[],["/leet",1],["/leet/code",2],["/leet/code"],["/leet/code",3],["/leet/code"]]

	FileSystem *test = new FileSystem();
	cout << test->createPath("/leet", 1) << endl;
	cout << test->createPath("/leet/code", 2) << endl;
	cout << test->get("/leet/code") << endl;
	cout << test->createPath("/leet/code", 3) << endl;
	cout << test->get("/leet/code") << endl;
	return 0;
}
