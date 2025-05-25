#include <Solution.h>

int main(void) {
	vector<string> input = {"qw","rr","ll","vv","iw","wq","cc","wi","jj","iw","pp","iw","mm","ss","bb","oo","wi","dd","wq","ff","qi","qw","qi","qi","zz","wq","iw","wi","qq","qw","wi","hh","qi","pp","vv","wi","wq","wi","wi","wi","iw","qi","bb","qw","qi","rr"};
	Solution *test = new Solution();
	cout << test->longestPalindrome(input) << endl;
	return 0;
}
