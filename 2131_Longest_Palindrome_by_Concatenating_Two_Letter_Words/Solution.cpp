#include <Solution.h>

int Solution::longestPalindrome(vector<string> &words) {
	unordered_map<string, int> self;
	unordered_map<string, int> last;

	int result = 0;
	for (const auto& w : words) {
		string rs = w;
		reverse(rs.begin(), rs.end());
		if (last.count(rs) && last[rs] != 0) {
			result += 4;
			--last[rs];
			if (self.count(rs) && self[rs] != 0) {
				--self[rs];
			}
		} else {
			++last[w];
			if (rs == w) {
				++self[w];
			}
		}
	}
	int center = 0;
	for (const auto& e : self) {
		if (e.second != 0) {
			center = 2;
			break;
		}
	}
	return result + center;
}
