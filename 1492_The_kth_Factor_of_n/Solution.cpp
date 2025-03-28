#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

int Solution::kthFactor(int n, int k) {
	vector<int> pre, post;

	for (int i = 1; (i * i) <= n; ++i) {
		if (n % i)
			continue;
		pre.emplace_back(i);
		if (i != (n / i)) {
			post.emplace_back(n / i);
		}
	}
	if (k > (pre.size() + post.size())) {
		return -1;
	}
	if (k <= pre.size()) {
		return pre[k - 1];
	} else {
		return post[post.size() - (k - pre.size())];
	}
}
