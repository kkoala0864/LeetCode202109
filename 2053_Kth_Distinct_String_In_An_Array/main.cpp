#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"dgsz", "hbx", "ay", "ej", "k", "z", "vca", "kov", "pw", "qxwo", "f", "la", "cc", "ytzy", "jxtsz", "s", "qmx", "uuggx", "k", "ivb", "gcsbc", "a", "y", "y", "rldki", "a", "nal", "tq", "tb", "yl", "ktcbx", "jr", "rlmm", "e", "xcv", "oid", "du", "ucx", "wjom", "fep", "jpnz", "gslz", "af", "kbevd"};
	int k = 25;
	Solution *test = new Solution();
	cout << test->kthDistinct(input, k) << endl;
	return 0;
}
