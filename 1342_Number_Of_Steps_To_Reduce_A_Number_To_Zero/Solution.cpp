#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::numberOfSteps(int num) {
	int result = 0;
	while (num > 0) {
		++result;
		if (num & 1)
			num -= 1;
		else
			num /= 2;
	}
	return result;
}
/*
int Solution::numberOfSteps(int num) {
        if (num == 0) return 0;
        vector<int> dp(num + 1, 0);
        dp[1] = 1;
        for (int i = 2 ; i <= num ; ++i) {
                if (i & 1) dp[i] = dp[i-1] + 1;
                else dp[i] = dp[i/2] + 1;
        }
        return dp[num];
}
*/
