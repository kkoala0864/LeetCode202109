#include <Solution.h>
#include <thread>
#include <mutex>
#include <future>

string Solution::getNameSpace(const string& url) {
	int idx = url.find("://");
	if (idx == string::npos) return "";
	int end = url.find("/", idx + 3);
	return url.substr(0, end);
}

bool Solution::checkExist(const string& s, unordered_set<string>& us, mutex& mtx) {
	lock_guard<mutex> lock(mtx);
	if (us.count(s)) {
		return true;
	} else {
		us.emplace(s);
		return false;
	}
}

void Solution::dfs(const string& hostname, HtmlParser& htmlParser, const string& cur, unordered_set<string>& us, mutex& mtx) {
	vector<string> list = htmlParser.getUrls(cur);
	vector<future<void>> futures;

	for (const auto& s : list) {
		if (getNameSpace(s) != hostname) continue;
		if (checkExist(s, us, mtx)) {
			continue;
		}
		futures.emplace_back(async(launch::async, dfs, hostname, ref(htmlParser), s, ref(us), ref(mtx)));
	}
	for (auto& f : futures) f.get();
}

vector<string> Solution::crawl(string startUrl, HtmlParser htmlParser) {
	unordered_set<string> us;
	mutex mtx;

	us.emplace(startUrl);
	dfs(getNameSpace(startUrl), htmlParser, startUrl, us, mtx);;

	vector<string> result;
	for (const auto& s : us) {
		result.emplace_back(s);
	}
	return result;
}
