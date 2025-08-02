class RandomizedSet {
public:
    unordered_map<int,int> indexmapping;
    vector<int> elements;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(indexmapping.count(val))return false;

        elements.push_back(val);
        indexmapping[val]=elements.size()-1;

        return true;
    }
    
    bool remove(int val) {
        if(!indexmapping.count(val))return false;
        int ind = indexmapping[val];
        indexmapping[elements[elements.size()-1]]=ind;
        swap(elements[elements.size()-1],elements[ind]);
        
        elements.pop_back();
        indexmapping.erase(val);

        return true;
    }
    
    int getRandom() {
        return elements[rand()%elements.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */