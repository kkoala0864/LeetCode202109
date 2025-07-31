#include <Solution.h>

int Solution::subarrayBitwiseORs(vector<int>& arr) {
	unordered_set<int> us;
	unordered_set<int> cur;
	for (const auto& v : arr) {
		unordered_set<int> next;
		for (const auto& e : cur) {
			next.emplace(e | v);
			us.emplace(e | v);
		}
		next.emplace(v);
		us.emplace(v);
		cur = std::move(next);
	}
	return us.size();
}
