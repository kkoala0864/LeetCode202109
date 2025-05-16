#include <data_type.h>

class HtmlParser {
	public:
		vector<string> getUrls(string url);
};

class Solution {
public:
	Solution() {
	}
	vector<string> crawl(string startUrl, HtmlParser htmlParser);
	static string getNameSpace(const string& url);
	static bool checkExist(const string& s, unordered_set<string>& us, mutex& mtx);
	static void dfs(const string& hostname, HtmlParser& htmlParser, const string& cur, unordered_set<string>& us, mutex& mtx);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
