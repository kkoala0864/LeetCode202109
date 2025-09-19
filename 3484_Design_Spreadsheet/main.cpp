#include <Solution.h>

int main(void) {
	//["Spreadsheet", "getValue", "setCell", "getValue", "setCell", "getValue", "resetCell", "getValue"]
	//[[3], ["=5+7"], ["A1", 10], ["=A1+6"], ["B2", 15], ["=A1+B2"], ["A1"], ["=A1+B2"]]
	int rows = 3;
	Spreadsheet* test = new Spreadsheet(rows);
	cout << test->getValue("=5+7") << endl;
	test->setCell("A1", 10);
	cout << test->getValue("=A1+6") << endl;
	test->setCell("B2", 15);
	cout << test->getValue("=A1+B2") << endl;
	test->resetCell("A1");
	cout << test->getValue("=A1+B2") << endl;
	return 0;
}
