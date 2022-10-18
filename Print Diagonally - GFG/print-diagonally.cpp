//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{
		// Your code goes here
		vector<int> v;
         int x=0,y=0;
         for(int i=0;i<N;i++){
             int tempx=x,tempy=y;
             for(int j=0;j<=i;j++){
                 v.push_back(A[tempy][tempx]);
                 tempx--;
                 tempy++;
             }
             x+=1;
         }
         x=N-1;y=1;
         for(int i=0;i<N-1;i++){
             int tempx=x,tempy=y;
             for(int j=0;j<N-i-1;j++){
                 v.push_back(A[tempy][tempx]);
                 tempx--;
                 tempy++;
             }
             y+=1;
         }
         return v;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends