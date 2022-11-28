//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    using ll = long long ; 
	    ll l = -1 , r = -1 ;
	    ll i = 0 ;
	    ll maxSum = 0 , sum , len ; 
	    while(i < n){
	        sum = 0 , len = 0; 
	        ll startIdx = i ;
	        while(i < n and a[i] >= 0)
	            sum += a[i++] , len++ ; 
	        if(len and sum > maxSum)
	            maxSum = sum , l = startIdx , r = i - 1 ;
	        while(i < n and a[i] < 0) i++ ; 
	    }
	    if(l == -1) return {-1} ; 
	    vector<int> ans(a + l , a + r + 1) ;
	    return ans ;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends