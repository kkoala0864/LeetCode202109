#include <Solution.h>

int Solution::longestDecomposition(string text) {
	int size = text.size();
	int l = 0;
	int r = size - 1;

	string pres, posts;

	int result = 0;
	while (l <= r) {
		pres.push_back(text[l]);
		posts = string(1, text[r]) + posts;
		if (pres == posts) {
			if (l < r) {
				result += 2;
				pres.clear();
				posts.clear();
			}
		}
		++l;
		--r;
	}
	if (!pres.empty()) {
		++result;
	}
	return result;
}
