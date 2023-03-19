class TrieNode {
public:
    bool isEndOfWord;
    unordered_map<char, TrieNode*> children;
    
    TrieNode() {
        isEndOfWord = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children.count(c)) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
    }
    
    bool searchHelper(string word, int i, TrieNode* curr) {
        if (i == word.length()) {
            return curr->isEndOfWord;
        }
        char c = word[i];
        if (c != '.') {
            if (!curr->children.count(c)) {
                return false;
            }
            return searchHelper(word, i+1, curr->children[c]);
        } else {
            for (auto it : curr->children) {
                if (searchHelper(word, i+1, it.second)) {
                    return true;
                }
            }
            return false;
        }
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};
