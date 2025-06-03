#include <data_type.h>

class Trie {
	public :
		map<string, Trie*> children;
		map<string, string> fileContent;
};

class FileSystem {
public:
	pair<Trie*, string> cd(string path, Trie* root) {
		auto iter = root;
		int ci = 0;
		int ni = path.find("/", ci + 1);
		string cur;
		while (ni != string::npos) {
			cur = path.substr(ci + 1, ni - ci - 1);
			if (iter->children[cur] == 0) iter->children[cur] = new Trie();
			iter = iter->children[cur];
			ci = ni;
			ni = path.find("/", ci + 1);
		}
		cur = path.substr(ci + 1);
		return pair<Trie*, string>(iter, cur);
	}

	FileSystem() {
		root = new Trie();
	}

	vector<string> ls(string path) {
		auto [iter, lastPath] = cd(path, root);
		set<string> s;
		if (lastPath.empty()) {
			for (const auto& e : iter->children) {
				s.emplace(e.first);
			}
			for (const auto& e : iter->fileContent) {
				s.emplace(e.first);
			}
		} else {
			if (iter->fileContent.count(lastPath)) {
				s.emplace(lastPath);
			} else if (iter->children.count(lastPath)) {
				iter = iter->children[lastPath];
				for (const auto& e : iter->children) {
					s.emplace(e.first);
				}
				for (const auto& e : iter->fileContent) {
					s.emplace(e.first);
				}
			}
		}
		vector<string> result;
		for (const auto& v : s) {
			result.emplace_back(v);
		}
		return result;
	}

	void mkdir(string path) {
		auto [iter, lastPath] = cd(path, root);
		if (!lastPath.empty() && iter->children[lastPath] == 0) {
			iter->children[lastPath] = new Trie();
		}
	}

	void addContentToFile(string filePath, string content) {
		auto [iter, lastPath] = cd(filePath, root);
		iter->fileContent[lastPath] += content;
	}

	string readContentFromFile(string filePath) {
		auto [iter, lastPath] = cd(filePath, root);
		return iter->fileContent[lastPath];
	}

private:
	Trie* root;
	virtual ~FileSystem() {
	}
	FileSystem &operator=(const FileSystem &source);
	FileSystem(const FileSystem &);
};
