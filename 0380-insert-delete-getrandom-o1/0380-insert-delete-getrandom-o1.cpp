class RandomizedSet {
public:
    unordered_set<int> random;
    int count;
    int size=0;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(random.count(val))return false;
        
        random.insert(val);
        return true;
        size++;
    }
    
    bool remove(int val) {
        if(!random.count(val))return false;

        random.erase(val);
        return true;
        size--;
    }
    
    int getRandom() {

        return *(next(random.begin(),rand()%random.size()));
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */