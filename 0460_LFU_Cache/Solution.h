#include <unordered_map>

using std::unordered_map;

struct Node {
	int key;
	int val;
	int cnt;
	Node* next;
	Node* prev;
	Node(int k, int v) : key(k), val(v) {
		cnt = 1;
	}
};

struct List {
	int len;
	Node* head, *tail;

	List() {
		head = new Node(0, 0);
		tail = new Node(0, 0);
		head->next = tail;
		tail->prev = head;
		len = 0;
	}

	void addNode(Node* node) {
		++len;
		node->next = head->next;
		node->prev = head->next->prev;
		head->next->prev = node;
		head->next = node;
	}

	void deleteNode(Node* node) {
		node->prev->next = node->next;
		node->next->prev = node->prev;
		--len;
	}
};

class LFUCache {
    public :
	    void updateFreqMap(Node* node) {
		addrOfKey.erase(node->key);
		freqListMap[node->cnt]->deleteNode(node);
		if (node->cnt == minFreq && freqListMap[node->cnt]->len == 0) {
			++minFreq;
		}

		List* list = freqListMap.count(node->cnt + 1) > 0 ? freqListMap[node->cnt + 1] : new List();

		++node->cnt;
		list->addNode(node);
		freqListMap[node->cnt] = list;
		addrOfKey[node->key] = node;
	    }

	    LFUCache(int capacity) {
		    cacheSize = capacity;
		    minFreq = 0;
		    curSize = 0;
	    }

	    int get(int key) {
		    if (addrOfKey.count(key) == 0) return -1;
		    Node* node = addrOfKey[key];
		    int result = node->val;
		    updateFreqMap(node);
		    return result;
	    }

	    void put(int key, int value) {
		    if (cacheSize == 0) return;

		    if (addrOfKey.count(key) != 0) {
			    addrOfKey[key]->val = value;
			    updateFreqMap(addrOfKey[key]);
		    } else {
			    if (cacheSize == curSize) {
				    List* list = freqListMap[minFreq];
				    Node* removeNode = list->tail->prev;
				    int removeKey = removeNode->key;
				    addrOfKey.erase(removeKey);
				    freqListMap[minFreq]->deleteNode(removeNode);
				    --curSize;
			    }

			    ++curSize;
			    minFreq = 1;
			    List* list = freqListMap.count(minFreq) > 0 ? freqListMap[minFreq] : new List();
			    Node* node = new Node(key, value);
			    list->addNode(node);
			    addrOfKey[key] = node;
			    freqListMap[minFreq] = list;
		    }
	    }
    private :
	    unordered_map<int, Node*> addrOfKey;
	    unordered_map<int, List*> freqListMap;
	    int minFreq, curSize;
	    int cacheSize;
	    virtual ~LFUCache() {}
	    LFUCache& operator=(const LFUCache& source);
	    LFUCache(const LFUCache&);
};

