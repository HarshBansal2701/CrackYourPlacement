class RandomizedCollection {
    vector<int> v;
    unordered_map<int,unordered_set<int>> mp;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool ans = true;
        if(mp.contains(val)){
            ans = false;
        }
        v.push_back(val);
        mp[val].insert(v.size()-1);
        return ans;
    }
    
    bool remove(int val) {
        if(!mp.contains(val)){
            return false;
        }

        int replaceIndex = *mp[val].begin();
        mp[val].erase(replaceIndex);
        if(mp[val].empty()){
            mp.erase(val);
        }

        int lastValue = v.back();
        if(replaceIndex != v.size()-1){
            swap(v[replaceIndex], v[v.size()-1]);
            mp[lastValue].erase(v.size()-1);
            mp[lastValue].insert(replaceIndex);

        }
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */