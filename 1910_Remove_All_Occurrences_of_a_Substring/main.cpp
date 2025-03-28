#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1 = "kpygkivtlqoockpygkivtlqoocssnextkqzjpycbylkaondsskpygkpygkivtlqoocssnextkqzjpkpygkivtlqoocssnextkqzjpycbylkaondsycbylkaondskivtlqoocssnextkqzjpycbylkaondssnextkqzjpycbylkaondshijzgaovndkjiiuwjtcpdpbkrfsi", s2 = "kpygkivtlqoocssnextkqzjpycbylkaonds";
	string result = "hijzgaovndkjiiuwjtcpdpbkrfsi";
	Solution *test = new Solution();
	cout << result << endl;
	cout << test->removeOccurrences(s1, s2) << endl;
	return 0;
}
