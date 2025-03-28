#include <string>

using std::string;

struct DNode
{
	DNode *next;
	DNode *prev;
	string url;
};

class BrowserHistory {
public:
	BrowserHistory() {
	}
	void insertToTail(DNode *node) {
		node->prev = tail->prev;
		node->next = tail;
		tail->prev->next = node;
		tail->prev = node;
	}

	void remove(DNode *node) {
		if (node == tail)
			return;
		node->next->prev = node->prev;
		node->prev->next = node->next;
		delete node;
	}

	BrowserHistory(string homepage) {
		head = new DNode();
		tail = new DNode();
		head->next = tail;
		head->prev = tail;
		tail->next = head;
		tail->prev = head;
		DNode *node = new DNode();
		node->url = homepage;
		cur = node;
		insertToTail(node);
	}

	void visit(string url) {
		DNode *iter = cur->next;
		while (iter != tail) {
			DNode *next = iter->next;
			remove(iter);
			iter = next;
		}
		DNode *node = new DNode();
		node->url = url;
		insertToTail(node);
		cur = cur->next;
	}

	string back(int steps) {
		while (steps--) {
			if (cur->prev == head)
				break;
			cur = cur->prev;
		}
		return cur->url;
	}

	string forward(int steps) {
		while (steps--) {
			if (cur->next == tail)
				break;
			cur = cur->next;
		}
		return cur->url;
	}

private:
	DNode *head;
	DNode *tail;
	DNode *cur;
	virtual ~BrowserHistory() {
	}
	BrowserHistory &operator=(const BrowserHistory &source);
	BrowserHistory(const BrowserHistory &);
};
