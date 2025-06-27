#include <Solution.h>

Node* Solution::findRoot(vector<Node*> tree) {
	int sum = 0;
	for (const auto& t : tree) {
		if (!t) continue;
		sum += t->val;
		for (const auto& c : t->children) {
			sum -= c->val;
		}
	}
	for (const auto& n : tree) {
		if (!n) continue;
		if (n->val == sum) return n;
	}
	return nullptr;
}
