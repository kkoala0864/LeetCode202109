#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1, 2}, {3}, {4}};
	Vector2D *test = new Vector2D(input);
	cout << test->next() << endl;
	cout << test->next() << endl;
	cout << test->next() << endl;
	cout << test->hasNext() << endl;
	cout << test->hasNext() << endl;
	cout << test->next() << endl;
	cout << test->hasNext() << endl;
	return 0;
}
