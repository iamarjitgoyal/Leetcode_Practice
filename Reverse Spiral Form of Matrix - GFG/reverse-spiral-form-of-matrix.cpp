//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        int top=0 , left = 0 , bottom = R-1 , right = C-1;
        vector<int>res;
        while(top<=bottom && left<=right){
            for(int i = left ; i <= right ; i++){
                res.push_back(a[top][i]);
            }
            top++;
            for(int i = top ; i <= bottom ; i++){
                res.push_back(a[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int i=right ; i >=left ; i--){
                    res.push_back(a[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom ; i >=top ; i--){
                    res.push_back(a[i][left]);
                }
                left++;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends