#include <Solution.h>
#include <iostream>
#include <queue>
#include <algorithm>

using std::queue;
using std::reverse;


int Solution::snakesAndLadders(vector<vector<int>>& board) {
	int size = board.size();
	reverse(board.begin(), board.end());
	for (int i = 0 ; i < board.size() ; ++i) {
		if (i & 1) {
			reverse(board[i].begin(), board[i].end());
		}
	}
	vector<int> cost(size * size, INT_MAX);
	queue<int> que, next;
	int result = 0;
	que.emplace(0);
	cost[0] = 0;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		if (cur == (size * size - 1)) return result;
		for (int i = 1 ; i <= 6 ; ++i) {
			if ((cur + i) >= (size * size)) break;
			int nx = (cur + i) / size;
			int ny = (cur + i) % size;
			if (board[nx][ny] != -1) {
				if (cost[board[nx][ny]-1] > cost[cur] + 1) {
					cost[board[nx][ny]-1] = cost[cur] + 1;
					next.emplace(board[nx][ny] - 1);
				}
			} else {
				if (cost[cur+i] > cost[cur] + 1) {
					cost[cur+i] = cost[cur] + 1;
					next.emplace(cur + i);
				}
			}
		}
		if (que.empty()) {
			++result;
			que = move(next);
		}
	}
	return -1;
}
