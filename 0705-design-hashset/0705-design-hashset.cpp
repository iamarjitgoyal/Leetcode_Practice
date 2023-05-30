class MyHashSet {
private:
    static const int SIZE = 10000;
    vector<list<int>> buckets;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashSet() {
        buckets.resize(SIZE);
    }

    void add(int key) {
        int index = hash(key);
        list<int>& bucket = buckets[index];
        for (int num : bucket) {
            if (num == key) {
                return;
            }
        }
        bucket.push_back(key);
    }

    void remove(int key) {
        int index = hash(key);
        list<int>& bucket = buckets[index];
        bucket.remove(key);
    }

    bool contains(int key) {
        int index = hash(key);
        list<int>& bucket = buckets[index];
        for (int num : bucket) {
            if (num == key) {
                return true;
            }
        }
        return false;
    }
};
