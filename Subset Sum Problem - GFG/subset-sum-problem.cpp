//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1));
        // for a particular index is particular sum is valid or not 
        for (int i = 0; i <= n; i++)
        {
                dp[i][0] = 1;
        }

        for (int i = 1; i <= sum; i++)
        {
            dp[0][i] = 0; 
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int s=1;s<=sum;s++)
            {
                if(s<arr[i-1])
                {
                    dp[i][s] = dp[i-1][s];
                }
                if(arr[i-1]<=s){
                    dp[i][s] = dp[i-1][s] | dp[i-1][s-arr[i-1]];
                }
            }
        }
        
        return  dp[n][sum];
        
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends