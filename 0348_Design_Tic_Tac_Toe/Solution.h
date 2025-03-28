#include <vector>

using std::vector;

class TicTacToe {
public:
	TicTacToe(int n) {
		_cnt = vector<vector<int>>(2, vector<int>(n + 1, 0));
		size = n;
	}

	int move(int row, int col, int player) {
		int offset = player == 1 ? 1 : -1;
		if (abs(_cnt[0][row] += offset) == size)
			return player;
		if (abs(_cnt[1][col] += offset) == size)
			return player;
		if (row == col && (abs(_cnt[0][size] += offset) == size))
			return player;
		if ((row + col == size - 1) && (abs(_cnt[1][size] += offset) == size))
			return player;
		return 0;
	}

private:
	vector<vector<int>> _cnt;
	int size;
	virtual ~TicTacToe() {
	}
	TicTacToe &operator=(const TicTacToe &source);
	TicTacToe(const TicTacToe &);
};
