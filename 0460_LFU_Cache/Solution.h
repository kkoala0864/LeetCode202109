#include <unordered_map>

using std::unordered_map;

struct Node
{
	Node *prev;
	Node *next;
	int key;
	int cnt;
	Node(int k)
	    : key(k), cnt(0) {
	}
};

struct List
{
	int len;
	Node *head;
	Node *tail;
	List()
	    : len(0) {
		head = new Node(-1);
		tail = new Node(-1);
		head->next = head->prev = tail;
		tail->next = tail->prev = head;
	}

	void addNode(Node *node) {
		node->prev = tail->prev;
		node->next = tail;
		node->prev->next = node;
		tail->prev = node;
		++len;
	}

	void deleteNode(Node *node) {
		--len;
		node->prev->next = node->next;
		node->next->prev = node->prev;
		node->next = node->prev = nullptr;
	}
};

class LFUCache {
public:
	void updateFreq(Node *node) {
		List *l = freqList[node->cnt];
		l->deleteNode(p[node->key]);
		if (node->cnt == minFreq && l->len == 0)
			++minFreq;

		l = freqList.count(node->cnt + 1) > 0 ? freqList[node->cnt + 1] : new List();
		l->addNode(node);
		++node->cnt;
		freqList[node->cnt] = l;
	}

	LFUCache(int capacity) {
		size = capacity;
		minFreq = 0;
	}

	int get(int key) {
		if (m.count(key) == 0)
			return -1;
		int result = m[key];
		updateFreq(p[key]);
		return result;
	}

	void put(int key, int value) {
		if (size == 0)
			return;
		if (m.count(key) != 0) {
			m[key] = value;
			updateFreq(p[key]);
		} else {
			if (m.size() == size) {
				Node *removeNode = freqList[minFreq]->head->next;
				p.erase(removeNode->key);
				m.erase(removeNode->key);
				freqList[minFreq]->deleteNode(removeNode);
			}

			m[key] = value;
			minFreq = 1;
			List *l = freqList.count(minFreq) > 0 ? freqList[minFreq] : new List();
			Node *node = new Node(key);
			l->addNode(node);
			p[key] = node;
			++node->cnt;
			freqList[minFreq] = l;
		}
	}

private:
	unordered_map<int, List *> freqList;
	unordered_map<int, Node *> p;
	unordered_map<int, int> m;
	int minFreq;
	int size;
	virtual ~LFUCache() {
	}
	LFUCache &operator=(const LFUCache &source);
	LFUCache(const LFUCache &);
};
