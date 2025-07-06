#include <Solution.h>

bool check(const string& text, int w, int h, int fs, FontInfo& fi) {
	for (const auto& c : text) {
		int cw = fi.getWidth(fs, c);
		int ch = fi.getHeight(fs);
		if (ch > h) return false;
		if (cw <= w) w -= cw;
		else return false;
	}
	return true;
}

int Solution::maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
	int l = 0, r = fonts.size() - 1;
	int mid = 0;

	while (l < r) {
		mid = r - ((r - l) >> 1);

		if (check(text, w, h, fonts[mid], fontInfo)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	return check(text, w, h, fonts[l], fontInfo) ? fonts[l] : -1;
}
