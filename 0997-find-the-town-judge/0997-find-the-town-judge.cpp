class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int sz = trust.size(); 
        vector<int> arr(n+1, 0);
        for(int i=0; i<sz; i++)
            arr[trust[i][1]]++, arr[trust[i][0]]--;
        for(int i=1; i<n+1; i++)
            if(arr[i]==n-1)  return i;
        return -1;
    }
};