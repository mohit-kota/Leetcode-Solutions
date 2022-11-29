
class RandomizedSet {
public:
    vector<int>vec;
    map<int,int>mp;
    RandomizedSet()
    {
           
    } 
    
    bool insert(int val) 
    {
       if(find(vec.begin(),vec.end(),val)!=vec.end())
       {
          return false; 
       }
       vec.push_back(val);
        return true; 
    }
    
    bool remove(int val) 
    {
    
        auto it = find(vec.begin(),vec.end(),val);
        if(it!=vec.end())
        {
            vec.erase(it);
            return true;
        }
        return false;
    }
    
    int getRandom() 
    {
        return vec[rand()%vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */