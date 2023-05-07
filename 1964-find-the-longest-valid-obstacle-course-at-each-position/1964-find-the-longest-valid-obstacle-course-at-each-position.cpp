class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n);
        vector<int> dp;
        
        for(int i=0;i<n;i++){
            int idx = upper_bound(dp.begin(), dp.end(), obstacles[i])-dp.begin();
            ans[i] = idx+1;
            
            if(idx==dp.size()){
                dp.push_back(obstacles[i]);
            }else{
                dp[idx] = obstacles[i];
            }
        }
        
        return ans;
    }
};
