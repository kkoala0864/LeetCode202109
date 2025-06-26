#include <data_type.h>

class SubrectangleQueries {
public:
	SubrectangleQueries(vector<vector<int>>& rectangle) {
		_rec = rectangle;
	}

	void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
		for (int i = row1 ; i <= row2 ; ++i) {
			for (int j = col1 ; j <= col2 ; ++j) {
				_rec[i][j] = newValue;
			}
		}
	}

	int getValue(int row, int col) {
		return _rec[row][col];
	}

private:
	vector<vector<int>> _rec;
	virtual ~SubrectangleQueries() {
	}
	SubrectangleQueries &operator=(const SubrectangleQueries &source);
	SubrectangleQueries(const SubrectangleQueries &);
};
