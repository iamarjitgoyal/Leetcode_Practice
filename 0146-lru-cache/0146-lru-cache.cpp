class LRUCache {
private:
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    
    int cap;
    std::unordered_map<int, Node*> map;
    Node* head;
    Node* tail;
    
    void move_to_front(Node* node) {
        if (node == head) {
            return;
        }
        if (node == tail) {
            tail = tail->prev;
        } else {
            node->next->prev = node->prev;
        }
        node->prev->next = node->next;
        node->next = head;
        head->prev = node;
        node->prev = nullptr;
        head = node;
    }
    
    void remove_tail() {
        map.erase(tail->key);
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
    }
    
public:
    LRUCache(int capacity): cap(capacity), head(nullptr), tail(nullptr) {}
    
    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) {
            return -1;
        }
        Node* node = it->second;
        move_to_front(node);
        return node->val;
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        if (it != map.end()) {
            Node* node = it->second;
            node->val = value;
            move_to_front(node);
        } else {
            Node* node = new Node(key, value);
            map.insert({key, node});
            if (head == nullptr) {
                head = tail = node;
            } else {
                node->next = head;
                head->prev = node;
                head = node;
            }
            if (map.size() > cap) {
                remove_tail();
            }
        }
    }
};
