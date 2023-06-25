class DataStream {
public:
    deque<int>dq;
    int tar,wid;
    DataStream(int value, int k) {
        dq.clear();
        tar = value;
        wid = k;
    }
    
    bool consec(int num) {
        if(!dq.empty()){
            
            if(num==tar)
            {
                dq.push_back(num);
                if(dq.size()>=wid)
                {
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                dq.clear();
            }
            
        }
        else{
            if(num==tar)
            {
                
            dq.push_back(num);
            }
            if(wid==1 && num==tar)
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */