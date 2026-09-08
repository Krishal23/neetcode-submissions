class LRUCache {
public:
    unordered_map<int,list<int>::iterator>mpIt;
    unordered_map<int,int>val;
    int sz;
    list<int>cache;
    LRUCache(int capacity) {
        sz=capacity;
    }
    
    int get(int key) {
        if(!mpIt.count(key))return -1;
        cache.erase(mpIt[key]);
        cache.push_front(key);
        mpIt[key]=cache.begin();
        return val[key];
        
    }
    
    void put(int key, int value) {
        if(mpIt.count(key)){
            cache.erase(mpIt[key]);
        }
        cache.push_front(key);
        mpIt[key]=cache.begin();
        val[key]=value;
        if(cache.size()>sz){
            mpIt.erase(cache.back());
            cache.pop_back();
        }
    }
};
