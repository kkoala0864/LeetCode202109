#include <Solution.h>
#include <cmath>

vector<int> Solution::countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
	vector<int> result;
	vector<vector<int>> cell(501, vector<int>(501, 0));
	for (const auto& p : points) {
		++cell[p[1]][p[0]];
	}
	for (int i = 0 ; i <= 500 ; ++i) {
		for (int j = 1 ; j <= 500 ; ++j) {
			cell[i][j] += cell[i][j-1];
		}
	}

	for (const auto& q : queries) {
		int cx = q[0], cy = q[1] , cr = q[2];

	        int rr = cr * cr, cnt = 0;
		for (int y = max(0, cy - cr) ; y <= min(500, cy + cr) ; ++y) {
			int dy = y - cy;
			int dy2 = dy * dy;
			if (rr < dy2) continue;
			int x = sqrt(rr - dy2);
			int l = max(0, cx - x);
			int r = min(500, cx + x);
			cnt += (cell[y][r] - (l == 0 ? 0 : cell[y][l-1]));
		}
		result.emplace_back(cnt);
	}
	return result;
}
