class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(!n) return 0;
        for(int i=0;i<n;i++){
             if(citations[i] >= n-i) return n-i;   // The first element whose value is more than the length of remaining array. 
			 //So return the remaining length which is the answer.
        }
        return 0;
    }
};