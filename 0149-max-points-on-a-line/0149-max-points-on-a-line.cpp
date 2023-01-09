class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        int n=points.size();
        if(n<2) return n;
        int maxCounter=0;
        // we are picking one point from the vector 
        for(int i=0;i<n-1;i++)
        {
            map<pair<int,int>,int>SlopeMap;
            int overlapping=0,verticalpoints=0,counter=0;
            for(int j=i+1;j<n;j++)
            {
                if(points[i][0]==points[j][0] && points[i][1]==points[j][1])
                {
                    overlapping++;
                }
                else if(points[i][0]==points[j][0])
                {
                    verticalpoints++;
                }
                else
                {
                    int xdiff=points[j][0]-points[i][0];
                    int ydiff=points[j][1]-points[i][1];
                    int hcf=__gcd(ydiff,xdiff);
                    xdiff=xdiff/hcf;
                    
                    ydiff=ydiff/hcf;
                    
                    pair<int,int> slope= make_pair(ydiff,xdiff);
                    
                    SlopeMap[ slope ]++;
                    
                    counter=max(counter,SlopeMap[ slope ]);
                }
                counter=max(counter,verticalpoints);
            }
            maxCounter=max(maxCounter,counter+overlapping+1);

        }
        return maxCounter;   
    }
};