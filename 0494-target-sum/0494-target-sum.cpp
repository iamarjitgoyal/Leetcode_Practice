class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(S>sum || S<-sum) return 0;
        vector<int> cur(2*sum+1), nxt(2*sum+1), *p_cur = &cur, *p_nxt = &nxt;
        cur[sum] = 1;
        for(int i=0;i<nums.size();i++) {
            for(int j=0;j<=2*sum;j++) 
                if(p_cur->at(j)) {
                    p_nxt->at(j+nums[i]) += p_cur->at(j);
                    p_nxt->at(j-nums[i]) += p_cur->at(j);
                }
            swap(p_cur,p_nxt);
            p_nxt->assign(2*sum+1,0);
        }
        return p_cur->at(S+sum);
    }
};