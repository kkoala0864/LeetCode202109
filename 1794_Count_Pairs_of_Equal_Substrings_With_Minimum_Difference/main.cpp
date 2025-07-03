#include <Solution.h>

int main(void) {
	string s1 = "dwtgmqucavlta";
	string s2 = "gupciaqadwtgm";
	Solution *test = new Solution();
	cout << test->countQuadruples(s1, s2) << endl;
	return 0;
}
