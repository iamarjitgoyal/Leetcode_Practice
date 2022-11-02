//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
            vector<int> x,y;
            
            x.push_back(0);x.push_back(n+1);
            y.push_back(0);y.push_back(m+1);
            
            for(int i=0;i<k;i++)
            {
                x.push_back(enemy[i][0]);
                y.push_back(enemy[i][1]);
            }
            
            sort(x.begin(),x.end());
            sort(y.begin(),y.end());
            
            int max_x = INT_MIN;
            int max_y = INT_MIN;
            
            for(int i=0;i<x.size()-1;i++)
            {
                max_x = max(max_x, x[i+1]-x[i]-1);
                max_y = max(max_y, y[i+1]-y[i]-1);
            }
            
            return max_x * max_y;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends