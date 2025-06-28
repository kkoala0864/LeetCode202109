#include <Solution.h>

// three case:
// size == 1
// is palindrome
// not palindrome
bool isPalin(const string& s) {
	int l = 0, r = s.size() - 1;
	while (l < r) {
		if (s[l++] != s[r--]) return false;
	}
	return true;
}

string Solution::nearestPalindromic(string n) {
	if (n.size() == 1) {
		if (n[0] == '0') return "1";
		else return string(1, n[0] - 1);
	}

	long long v = stoll(n);
	int size = n.size();
	int psize = size >> 1;

	vector<pair<long long, long long>> canidate;
	long long lb = stoll(string(size-1, '9'));
	canidate.emplace_back(pair<long long, long long>(abs(v - lb), lb));

	string ub = string(size + 1, '0');
	ub[0] = '1';
	ub.back() = '1';
	canidate.emplace_back(pair<long long, long long>(abs(v - stoll(ub)), stoll(ub)));

	string pre = n.substr(0, psize + (size % 2));
	if (!isPalin(n)) {
		string post = n.substr(0, psize);
		reverse(post.begin(), post.end());
		string palinStr = pre + post;
		canidate.emplace_back(pair<long long, long long>(abs(v - stoll(palinStr)), stoll(palinStr)));
	}

	long long preV = stoll(pre);
	long long plus = preV + 1;
	long long minus = preV - 1;
	string plusStr = to_string(plus);
	string minusStr = to_string(minus);
	string plusPost = plusStr.substr(0, psize);
	reverse(plusPost.begin(), plusPost.end());
	plusStr += plusPost;
	string minusPost = minusStr.substr(0, psize);
	reverse(minusPost.begin(), minusPost.end());
	minusStr += minusPost;
	canidate.emplace_back(pair<long long, long long>(abs(v - stoll(plusStr)), stoll(plusStr)));
	canidate.emplace_back(pair<long long, long long>(abs(v - stoll(minusStr)), stoll(minusStr)));
	sort(canidate.begin(), canidate.end());
	return to_string(canidate[0].second);
}
