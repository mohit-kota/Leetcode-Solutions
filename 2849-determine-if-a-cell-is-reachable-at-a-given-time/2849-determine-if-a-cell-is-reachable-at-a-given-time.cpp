class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) 
    {
        int xdiff = abs(sx-fx) , ydiff = abs(sy-fy);
        if(xdiff==0 and ydiff==0 and t==1) return false;
        
        if(min(xdiff,ydiff) + abs(xdiff-ydiff)<=t)
        {
            return true;
        }
        return false;
    }
};