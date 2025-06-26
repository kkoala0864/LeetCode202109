#include <data_type.h>

class Solution {
public:
	Solution() {
		i = 0;
	}
	string encode(string longUrl) {
		++i;
		string ret = to_string(i);
		m[ret] = longUrl;
		return ret;
	}

	string decode(string shortUrl) {
		return m[shortUrl];
	}

private:
	long long i;
	unordered_map<string, string> m;
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
