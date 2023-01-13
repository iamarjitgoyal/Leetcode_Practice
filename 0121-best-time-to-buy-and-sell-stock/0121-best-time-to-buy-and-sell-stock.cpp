class Solution {
public:
    int maxProfit(vector<int>& price) {
        int maxx=0;
        int ref = INT_MAX;
        vector<int> :: iterator it;
        for(it = price.begin()  ; it<price.end() ; it++){
            if(*it < ref)
                ref = *it;
            int temp = *it - ref;
            maxx = max(temp,maxx);
        }
        return maxx;
    }
};
