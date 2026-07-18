struct Node {
    int val;
    int key;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int k, int v){
        val = v;
        key = k;
    }
};
class LRUCache {
    unordered_map<int, Node*> cache;
    Node* head;
    int capacity;
public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        remove(cache[key]);
        insert(cache[key]);
        return cache[key]->val;
    }
    
    void put(int key, int value) {
        Node* node = new Node(key, value);

        if(cache.find(key)!=cache.end()){
            remove(cache[key]);
            delete cache[key];
            cache.erase(key);
        }

        if(cache.size() < capacity){
            insert(node);
            cache[key] = node;
            return;
        }
        else {
            Node* tmp = head->right;
            remove(tmp);
            cache.erase(tmp->key);
            delete tmp;
            insert(node);
            cache[key] = node;
        }
    }

    void insert(Node* node){
        if(head->left == nullptr){
            node->right = head;
            node->left = head;
            head->right = node;
            head->left = node;
        }else{
            node->left = head->left;
            node->right = head;
            head->left->right = node;
            head->left = node;
        }
        
    }

    void remove(Node* node){
        if(node->left==head && node->right==head){
            head->left = nullptr;
            head->right = nullptr;
            return;
        }
        node->left->right = node->right;
        node->right->left = node->left;
    }
};
