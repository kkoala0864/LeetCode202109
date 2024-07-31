#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;
using std::max;

int Solution::minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
	vector<int> dp(books.size() + 1, INT_MAX);

	dp[0] = 0;
	dp[1] = books[0][1];
	for (int i = 1 ; i < books.size() ; ++i) {
		int restOfThick = shelfWidth - books[i][0];
		int maxH = books[i][1];
		dp[i+1] = dp[i] + maxH;

		int j = i - 1;
		while (j >= 0 && (restOfThick - books[j][0] >= 0)) {
			restOfThick -= books[j][0];
			maxH = max(maxH, books[j][1]);
			dp[i+1] = min(dp[i+1], dp[j] + maxH);
			--j;
		}
	}
	return dp.back();
}
