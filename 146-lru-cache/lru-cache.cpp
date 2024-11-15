class LRUCache {
public:
    int size;
    list<int> lru;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    LRUCache(int capacity) {
        size = capacity;
    }
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        lru.erase(cache[key].second);
        lru.push_front(key);
        cache[key].second = lru.begin();
        return cache[key].first;
    }
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            lru.erase(cache[key].second);
        } else if (lru.size() == size) {
            int lruKey = lru.back();
            lru.pop_back();
            cache.erase(lruKey);
        }
        lru.push_front(key);
        cache[key] = {value, lru.begin()};
    }
};
