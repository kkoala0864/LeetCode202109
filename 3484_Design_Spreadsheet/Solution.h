#include <data_type.h>

class Spreadsheet {
public:
	Spreadsheet(int rows) {
		sheet = vector<vector<int>>(26, vector<int>(rows + 1, 0));
	}

	void setCell(string cell, int value) {
		if (cell.empty()) return;
		if (!isalpha(cell[0])) return;
		int col = cell[0] - 'A';
		int row = stoi(cell.substr(1));
		sheet[col][row] = value;
	}

	void resetCell(string cell) {
		setCell(cell, 0);
	}

	int parseValue(const string& s) {
		if (s.empty()) return 0;
		if (isdigit(s[0])) {
			return stoi(s);
		} else {
			int col = s[0] - 'A';
			int row = stoi(s.substr(1));
			return sheet[col][row];
		}
	}

	int getValue(string formula) {
		int pI = formula.find('+');
		string arg1 = formula.substr(1, pI - 1);
		string arg2 = formula.substr(pI + 1);

		int v1 = parseValue(arg1);
		int v2 = parseValue(arg2);
		return v1 + v2;
	}

private:
	vector<vector<int>> sheet;
	virtual ~Spreadsheet() {
	}
	Spreadsheet &operator=(const Spreadsheet &source);
	Spreadsheet(const Spreadsheet &);
};
