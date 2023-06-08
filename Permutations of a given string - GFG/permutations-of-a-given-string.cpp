//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<string> find_permutation(string S)
    {
        vector<string> permutations;
        sort(S.begin(), S.end());
        permute(S, 0, permutations);
        return permutations;
    }

private:
    void permute(string& S, int start, vector<string>& permutations)
    {
        if (start == S.length() - 1)
        {
            permutations.push_back(S);
            return;
        }

        for (int i = start; i < S.length(); i++)
        {
            if (i != start && S[i] == S[start])
                continue;

            swap(S[start], S[i]);
            permute(S, start + 1, permutations);
        }

        rotate(S.begin() + start, S.begin() + start + 1, S.end());
    }
};




//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends