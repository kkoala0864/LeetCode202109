#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"623986800","3","887298","695","794","6888794705","269409","59930972","723091307","726368","8028385786","378585"};
	Solution* test = new Solution();
	cout << test->kthLargestNumber(input, 11) << endl;
	return 0;
}

