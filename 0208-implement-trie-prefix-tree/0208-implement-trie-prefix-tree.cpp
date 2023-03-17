class TrieNode {
public:
    bool isEndOfWord;
    unordered_map<char, TrieNode*> children;

    TrieNode() {
        isEndOfWord = false;
    }
};


class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.count(c) == 0) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* node = findNode(word);
        return node != nullptr && node->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* node = findNode(prefix);
        return node != nullptr;
    }

private:
    TrieNode* root;

    TrieNode* findNode(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.count(c) == 0) {
                return nullptr;
            }
            curr = curr->children[c];
        }
        return curr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */