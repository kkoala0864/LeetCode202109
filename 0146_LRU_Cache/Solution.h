#include <vector>

using std::vector;

struct Node
{
	int val;
	int key;
	Node *next;
	Node *prev;
	Node() {
	}
	Node(int k, int v)
	    : key(k), val(v) {
	}
};

class LRUCache {
public:
	LRUCache(int capacity) {
		head = new Node(-1, -1);
		tail = new Node(-1, -1);
		head->next = tail;
		tail->prev = head;
		size = capacity;
		uMap = vector<Node *>(10001, nullptr);
		curSize = 0;
	}

	void Add(Node *node) {
		node->prev = head;
		node->next = head->next;
		head->next->prev = node;
		head->next = node;
		uMap[node->key] = node;
	}

	void remove(Node *node) {
		uMap[node->key] = nullptr;
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	int get(int key) {
		if (uMap[key] == nullptr)
			return -1;
		Node *node = uMap[key];
		remove(node);
		Add(node);
		return node->val;
	}

	void put(int key, int value) {
		if (uMap[key] == nullptr) {
			while (curSize >= size) {
				--curSize;
				remove(tail->prev);
			}
		} else {
			--curSize;
			remove(uMap[key]);
		}

		++curSize;
		Add(new Node(key, value));
	}

private:
	Node *head, *tail;
	vector<Node *> uMap;
	int curSize;
	int size;
	virtual ~LRUCache() {
	}
	LRUCache &operator=(const LRUCache &source);
	LRUCache(const LRUCache &);
};
