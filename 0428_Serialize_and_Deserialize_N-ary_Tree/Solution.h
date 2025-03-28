#include <data_type.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>

using std::cout;
using std::endl;
using std::queue;
using std::string;
using std::to_string;
using std::vector;

class Node {
public:
	int val;
	vector<Node *> children;

	Node() {
	}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node *> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	Solution() {
	}
	// Encodes a tree to a single string.
	string serialize(Node *root) {
		if (!root)
			return "";
		string result;
		queue<Node *> que, next;
		string nextStr;

		Node *dump = new Node(-1);
		dump->children.emplace_back(root);
		que.emplace(dump);

		while (!que.empty()) {
			auto cur = que.front();
			que.pop();

			for (const auto &n : cur->children) {
				nextStr += to_string(n->val);
				nextStr.push_back(',');
				next.emplace(n);
			}
			nextStr += "|,";

			if (que.empty()) {
				if (!next.empty()) {
					result += nextStr;
					nextStr.clear();
				}
				que = move(next);
			}
		}
		return result;
	}

	// 0 1 2 3 4
	int getV(const string &data, int &i) {
		int idx = data.find(",", i);
		int v = stoi(data.substr(i, idx - i));
		i = idx + 1;
		return v;
	}

	// Decodes your encoded data to tree.
	Node *deserialize(string data) {
		if (data.empty())
			return nullptr;
		int i = 0;
		Node *dummy = new Node(-1);
		queue<Node *> que, next;
		que.emplace(dummy);
		while (i < data.size()) {
			auto cur = que.front();
			que.pop();
			while (i < data.size() && data[i] != '|') {
				int v = getV(data, i);
				Node *node = new Node(v);
				cur->children.emplace_back(node);
				next.emplace(node);
			}
			i += 2;
			if (que.empty()) {
				que = move(next);
			}
		}
		return dummy->children[0];
	}

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
