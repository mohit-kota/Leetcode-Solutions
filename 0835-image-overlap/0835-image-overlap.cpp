/*
Linear Transformation:
find cells with ones. to move a 1 from A to a 1 from B, it'll take some transformation  (dx, dy).  
for another 1 cell in A to also overlap with a 1 cell in B will take the SAME (dx,dy). 
make a map of possible (dx,dy) and count the ones that have the same (dx,dy)

find [[i,j]...] of 1s for A, B
find all combos of each filtered array
calc the dx,dy and set to a map.  find the mapping that has the highest count and return

T: filtering takes O(N^2). combos takes a double for loop of N^2 * N^2 in the worst case. 
so N^2 + N^2 * N^2 ---> O(N^4)
S: O(N^2) for arrays space in the worst case of A and B filled with 1s



*/


class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = 0, n = img1.size();
        for(int i=-n;i<n;i++){
            //cout<<"i = "<<i<<endl;
            for(int j = -n;j<n;j++){
                int cntr = 0;
                for(int k =0 ;k<n;k++){
                    for(int l = 0;l<n;l++){
                        int X = i+k;
                        int Y = j+l;
                        if(X<n && X>=0 && Y<n && Y>=0 && img2[X][Y] == 1 && img1[k][l] == 1){
                            //cout<<"X and Y -> "<<X<<Y<<" i and j -> "<<i<<j<<endl;
                            cntr++;
                        }
                    }
                }
                //cout<<"for j = "<<j<<" cntr is  "<<cntr<<endl;
                ans = max(ans,cntr);
            }
            cout<<endl;
        }
        return ans;
    }
};