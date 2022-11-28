class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res(2);
        unordered_map<int,int> mp;
        set<int> s;
        for(int i=0;i<matches.size();i++)
        {
            mp[matches[i][1]]++;
            s.insert(matches[i][0]);
            s.insert(matches[i][1]);
        }
        for(auto it:s)
        {
            if(mp.find(it)!=mp.end())
            {
                if(mp[it]==1)
                res[1].push_back(it);
            }
            else 
                res[0].push_back(it);
        }
        return res;
    }
};