class Solution {
public:
    int minwindowsubstr(string s, string text)
    {
        vector<int> ct(26,0);
        int n=text.length();
        for(int i=0;i<n;i++) ct[text[i]-'A']++;
        int r=0,l=0,mi=INT_MAX;
        while(r<s.length()){
            ct[s[r]-'A']--;
            if(ct[s[r]-'A']>=0) n--;
            r++;
            while(l<r && n==0){
                mi=min(mi,r-l);
                ct[s[l]-'A']++;
                if(ct[s[l]-'A']>0) n++;
                l++;
            }
        }
        return mi;
    }
    
    int balancedString(string s) {
        int n=s.length();
        unordered_map<char,int> m;
        for(int i=0;i<n;i++) m[s[i]]++;
        int len=n/4;
        //cout<<len<<endl;
        string str="";
        for(auto it:m){
            if(it.second>len) str+=string(it.second-len,it.first);
        }
        if(str.length()==0) return 0;
        return minwindowsubstr(s,str);
    }
};