class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<int> indices(plantTime.size());
        
        // filling the indices array with indexes 
        iota(indices.begin(), indices.end(), 0);
        
        int result = 0 , curPlantTime = 0;
        
        // sort according the decreasing order of growTime 
        
        sort(indices.begin(),indices.end(),[&](int i,int j){
           return growTime[i]>growTime[j]; 
        });
        
        for(auto i : indices)
        {
            curPlantTime += plantTime[i];
            result = max(result,curPlantTime+growTime[i]);
        }
        
        return result;
        // return 0;
    }
};