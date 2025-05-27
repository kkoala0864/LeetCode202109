#include <Solution.h>

unsigned long long getKey(int p1, int p2) {
	unsigned long long ret = 0;
	return ((ret | (unsigned long long)(unsigned int)p1 << 32) | (unsigned long long)(unsigned int)p2);
}

vector<unsigned long long> getCorner(vector<int>& rectangles) {
	vector<unsigned long long> point;
	point.emplace_back(getKey(rectangles[0], rectangles[1]));
	point.emplace_back(getKey(rectangles[0], rectangles[3]));
	point.emplace_back(getKey(rectangles[2], rectangles[1]));
	point.emplace_back(getKey(rectangles[2], rectangles[3]));
	return point;
}

bool Solution::isRectangleCover(vector<vector<int>>& rectangles) {
	vector<int> maxR({INT_MAX, INT_MAX, INT_MIN, INT_MIN});

	unordered_set<long long> us;

	long long area = 0;
	for (int i = 0 ; i < rectangles.size() ; ++i) {
		maxR[0] = min(maxR[0], rectangles[i][0]);
		maxR[1] = min(maxR[1], rectangles[i][1]);
		maxR[2] = max(maxR[2], rectangles[i][2]);
		maxR[3] = max(maxR[3], rectangles[i][3]);
		area += ((long long)(rectangles[i][2] - rectangles[i][0]) * (long long)(rectangles[i][3] - rectangles[i][1]));

		auto point = getCorner(rectangles[i]);
		for (const auto& p : point) {
			if (us.count(p)) us.erase(p);
			else us.emplace(p);
		}
	}
	if (us.size() != 4) return false;
	auto maxCorner = getCorner(maxR);
	for (const auto& p : maxCorner) {
		if (us.count(p)) continue;
		return false;
	}

	return area == ((long long)(maxR[2] - maxR[0]) * (long long)(maxR[3] - maxR[1]));

}
