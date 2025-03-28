#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Trie *test = new Trie();
	test->insert("apple");
	cout << test->search("apple") << endl;
	cout << test->search("app") << endl;
	test->insert("app");
	cout << test->search("app") << endl;
	return 0;
}
