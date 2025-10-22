#include <Solution.h>

int main(void) {
	vector<int> v1 = {1,0,0,2,3};
	vector<int> v2 = {0,3,0,4,0};
	auto s1 = SparseVector(v1);
	auto s2 = SparseVector(v2);
	cout << s1.dotProduct(s2) << endl;
	return 0;
}
