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
        int n=img1.size();
        vector<pair<int,int>>vec_a;
        vector<pair<int,int>>vec_b;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1){
                    vec_a.push_back({i,j});
                }
                if(img2[i][j]==1){
                    vec_b.push_back({i,j});
                }
            }
        }
        int ans=0;
        map<pair<int,int>,int>mp;
        for(auto [i1,j1]:vec_a){
            for(auto [i2,j2]:vec_b){
                mp[{i1-i2,j1-j2}]++;
                ans=max(ans,mp[{i1-i2,j1-j2}]);
            }
        }
        return ans;
    }
};