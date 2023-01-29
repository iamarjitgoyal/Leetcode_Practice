class LFUCache {
private:
    int capacity;
    int size;
    unordered_map<int, pair<int, int>> cache; // key, value and usage count
    unordered_map<int, list<int>::iterator> iter; // key and its iterator in usage list
    unordered_map<int, list<int>> freq; // usage count and list of keys with that usage count
    int min_freq;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        min_freq = 0;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        else {
            int value = cache[key].first;
            int usage = cache[key].second;
            freq[usage].erase(iter[key]);
            if (freq[usage].empty() && usage == min_freq) {
                min_freq++;
            }
            usage++;
            cache[key] = {value, usage};
            freq[usage].push_back(key);
            iter[key] = --freq[usage].end();
            return value;
        }
    }
    
    void put(int key, int value) {
        if (capacity <= 0) {
            return;
        }
        if (cache.find(key) != cache.end()) {
            int usage = cache[key].second;
            freq[usage].erase(iter[key]);
            if (freq[usage].empty() && usage == min_freq) {
                min_freq++;
            }
            usage++;
            cache[key] = {value, usage};
            freq[usage].push_back(key);
            iter[key] = --freq[usage].end();
        }
        else {
            if (size == capacity) {
                auto key_to_remove = freq[min_freq].front();
                freq[min_freq].pop_front();
                iter.erase(key_to_remove);
                cache.erase(key_to_remove);
                size--;
            }
            cache[key] = {value, 1};
            freq[1].push_back(key);
            iter[key] = --freq[1].end();
            min_freq = 1;
            size++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */