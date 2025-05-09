#include <data_type.h>

class Trie {
	public :
		unordered_map<string, Trie*> child;
		int val = 0;
};

using namespace std;

class FileSystem {
public:
	FileSystem() {
		root = new Trie();
	}

	bool createPath(string path, int value) {
		if (path.empty() || path == "/") return false;

		int last = 0;
		int cur = 0;
		auto iter = root;
		while ((cur = path.find("/", last + 1)) != string::npos) {
			string s = path.substr(last, cur - last);
			if (iter->child.count(s) == 0) return false;
			iter = iter->child[s];
			last = cur;
		}
		string s = path.substr(last);
		if (iter->child.count(s)) return false;
		iter->child[s] = new Trie();
		iter->child[s]->val = value;
		return true;
	}

	int get(string path) {
		if (path.empty() || path == "/") return -1;
		int last = 0;
		int cur = 0;
		auto iter = root;
		while ((cur = path.find("/", last + 1)) != string::npos) {
			string s = path.substr(last, cur - last);
			if (iter->child.count(s) == 0) return -1;
			iter = iter->child[s];
			last = cur;
		}
		string s = path.substr(last);
		if (iter->child.count(s) == 0) return -1;
		iter = iter->child[s];
		return iter->val;
	}

private:
	Trie* root;
	virtual ~FileSystem() {
	}
	FileSystem &operator=(const FileSystem &source);
	FileSystem(const FileSystem &);
};
