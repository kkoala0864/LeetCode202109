#include <vector>

using std::vector;

class NumMatrix {
    public :
	    NumMatrix(vector<vector<int>>& matrix) {
		_m = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int i = 0 ; i < matrix.size() ; ++i) {
			for (int j = 0 ; j < matrix[0].size() ; ++j) {
				if (i == 0 && j == 0) _m[i][j] = 0;
				else if (j == 0) _m[i][j] = _m[i-1][j];
				else if (i == 0) _m[i][j] = _m[i][j-1];
				else _m[i][j] = _m[i][j-1] + _m[i-1][j] - _m[i-1][j-1];
				_m[i][j] += matrix[i][j];
			}
		}
	    }

	    // result = _m[row2][col2] - _m[row1-1][col2] - _m[row2][col1-1] + _m[row1-1][col1-1];
	    int sumRegion(int row1, int col1, int row2, int col2) {
		    if (row1 == 0 && col1 == 0) return _m[row2][col2];
		    int result = _m[row2][col2];
		    if (row1 != 0) result -= _m[row1-1][col2];
		    if (col1 != 0) result -= _m[row2][col1-1];
		    if (row1 != 0 && col1 != 0) result += _m[row1-1][col1-1];
		    return result;
	    }
    private :
	    vector<vector<int>> _m;
	    virtual ~NumMatrix() {}
	    NumMatrix& operator=(const NumMatrix& source);
	    NumMatrix(const NumMatrix&);
};

