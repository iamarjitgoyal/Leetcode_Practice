class Solution {
public:
    bool canBeSold(int maxQty,vector<int> &inv,int orders)
    {
        int n = inv.size();
        for(int i=n-1;i>=0;i--)
        {
            int ballsToBeSold = max(0,inv[i]-maxQty);
            orders-=ballsToBeSold;
            if(orders<0)
                return false;
        }
        return true;
    }
    int calcProfit(int low,vector<int> &inv,int orders)
    {
        int mod = 1e9+7;
        long long maxBallinInv = low;
        int ans=0;
        long long futureCost = (maxBallinInv*(maxBallinInv+1))/2;
        for(int i=0;i<inv.size();i++)
        {
            if(inv[i]<=maxBallinInv)
                continue;
            long long balls = inv[i];
            long long presentCost = (balls* (balls+1))/2;
            ans = (ans%mod + (int)((presentCost - futureCost)%mod))%mod;
            orders -= (inv[i]-maxBallinInv);
        }
        ans = (ans%mod + (orders*maxBallinInv)%mod)%mod;
        return ans%mod;        
    }
    
    int maxProfit(vector<int>& inv, int orders) 
    {
        sort(inv.begin(),inv.end());
        int low = 0,high = inv.back();
        while(low<high)
        {
            int mid = low + (high-low)/2;
            if(canBeSold(mid,inv,orders))
                high=mid;
            else
                low=mid+1;
        }
        return calcProfit(low,inv,orders);
    }
};