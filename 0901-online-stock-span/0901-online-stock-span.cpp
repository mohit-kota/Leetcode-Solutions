class StockSpanner {
public:
    vector<int>vec;
    StockSpanner() {
        if(vec.size()>0)
        {
            vec.clear();
        }
    }
    
    int next(int price)
    {
        vec.push_back(price);
        int span = 1; // including today 
        int temp = 1;
        for(int i=vec.size()-2;i>=0;i--)
        {
            if(vec[i]<=price)
            {
                temp+=1;
                span = max(temp,span);
            }
            else
            {
                break;
            }
        }
        return span;
    }
            
    
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */