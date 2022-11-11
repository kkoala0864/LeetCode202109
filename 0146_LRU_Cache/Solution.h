#include <unordered_map>

struct Node{
	int val;
	int key;
	Node* next;
	Node* prev;
	Node() {}
	Node(int k, int v) : key(k), val(v) {}
};

using std::unordered_map;

class LRUCache {
    public :
	LRUCache(int capacity) {
		head = new Node(-1, -1);
		tail = new Node(-1, -1);
		head->next = tail;
		tail->prev = head;
		size = capacity;
	}

	void Add(int key, int val, Node* prev) {
		Node* node = new Node(key, val);
		node->prev = prev;
		node->next = prev->next;
		prev->next->prev = node;
		prev->next = node;
		uMap[key] = node;
	}

	void remove(Node* node) {
		uMap.erase(node->key);
		Node* next = node->next;
		Node* prev = node->prev;
		prev->next = next;
		next->prev = prev;
		delete(node);
	}

	int get(int key) {
		if (uMap.count(key) == 0) return -1;
		Node* node = uMap[key];
		int val = node->val;
		remove(node);
		Add(key, val, head);
		return val;
	}

	void put(int key, int value) {
		if (uMap.count(key) == 0) {
			while (uMap.size() >= size) {
				remove(tail->prev);
			}
		} else {
			remove(uMap[key]);
		}

		Add(key, value, head);
	}
    private :
	Node* head, *tail;
	unordered_map<int, Node*> uMap;
	int size;
        virtual ~LRUCache() {}
        LRUCache& operator=(const LRUCache& source);
        LRUCache(const LRUCache&);
};

