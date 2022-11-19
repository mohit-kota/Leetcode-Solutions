class Solution {
public:
    int getRotation(vector<int>a,vector<int>b,vector<int>c)
    {
        // x2 - x1 * y3 - y1
        return ((b[0] - a[0])*(c[1]-a[1])) - ((b[1]-a[1])*(c[0]-a[0]));
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) 
    {
        
        // convex - hull algorithm
        
        int n  = trees.size();
        if(n<=3)
        {
            return trees;
        }
        
        // sort in lexicographically order
        sort(trees.begin(),trees.end());
        
        
        //construction of upperHull 
        vector<vector<int>>upperHull;
        upperHull.push_back(trees[0]);
        upperHull.push_back(trees[1]);
        
        // now traverse from 3rd point in trees array 
        
        for(int i=2;i<n;i++)
        {
            int us = upperHull.size();
            while(upperHull.size()>=2 and getRotation(upperHull[us-2],upperHull[us-1],trees[i])>0)
            {
                upperHull.pop_back();
                us--;
            }
            upperHull.push_back(trees[i]);
        }
        
        // similarly construction of lowerHull
        vector<vector<int>>lowerHull;
        lowerHull.push_back(trees[n-1]);
        lowerHull.push_back(trees[n-2]);
        
        // now traverse from last 3rd element in trees array 
        
        for(int i=n-3;i>=0;i--)
        {
            int ls = lowerHull.size();
            while(lowerHull.size()>=2 and getRotation(lowerHull[ls-2],lowerHull[ls-1],trees[i])>0){
                lowerHull.pop_back();
                ls--;
            }
            lowerHull.push_back(trees[i]);
        }
        
        // Pop the last elements as they would've occurred in both lists
        upperHull.pop_back();
        lowerHull.pop_back();
        for (int i = 0; i < lowerHull.size(); i++) {
            upperHull.push_back(lowerHull[i]);
        }
        
		// Sort and remove duplicate elements. (It is begging for a different approach!!)
        sort(upperHull.begin(), upperHull.end());
        upperHull.erase(std::unique(upperHull.begin(), upperHull.end()), upperHull.end());
        
        return upperHull;
        
    }
};