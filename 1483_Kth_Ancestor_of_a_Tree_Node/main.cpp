#include <Solution.h>

int main(void) {
	// ["TreeAncestor","getKthAncestor"]
	// [[2,[-1,0]],[1,2]]

	int n = 2;
	vector<int> parent({-1,0});
	TreeAncestor* test = new TreeAncestor(n, parent);
	cout << test->getKthAncestor(1, 2) << endl;
	return 0;
}
