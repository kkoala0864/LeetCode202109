#include <Solution.h>

// 1 2 3 4 5
vector<int> Solution::beautifulArray(int n) {
	vector<int> result(1, 1);
	vector<int> next;

	while (result.size() < n) {
		for (const auto& v : result) {
			int nv = v << 1;
			if (nv <= n) next.emplace_back(nv);
		}

		for (const auto& v : result) {
			int nv = (v << 1) - 1;
			if (nv <= n) next.emplace_back(nv);
		}
		result = move(next);
	}
	return result;
}
