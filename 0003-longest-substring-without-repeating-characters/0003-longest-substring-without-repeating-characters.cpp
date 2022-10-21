class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0){
            return 0;
        }
        set<char> st;
        int Max=0;
        int end=0,start=0;
        while(start<n)
        {
            if(st.count(s[start])==0)
            {
                st.insert(s[start]);
                Max=max(Max,(int)st.size());
                start++;
            }
            else
            {
                st.erase(s[end]);
                end++;
            }
        }
        return Max;
    }
};