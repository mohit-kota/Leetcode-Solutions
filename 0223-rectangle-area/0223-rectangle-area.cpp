class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) 
    {
        int area_of_triangle1 = (ax2 - ax1) * (ay2 - ay1);
        int area_of_traingle2 = (bx2 - bx1) * (by2 - by1);
        
        // x overlap 
        int left = max(ax1,bx1);
        int right = min(ax2,bx2);
        int xoverlap = right - left;
        
        // y overlap 
        int left1 = max(ay1,by1);
        int right1 = min(ay2,by2);
        
        int yoverlap = right1 - left1;
        int areaofoverlap = 0;
        if(xoverlap>0 and yoverlap>0)
        {
            areaofoverlap = xoverlap * yoverlap;
        }
        
        return (area_of_triangle1 + area_of_traingle2) - areaofoverlap;
    }
};