class Solution {
public:
    bool isAnswer(vector<int>&A , int mid ,int m ){
        int initial= 1;  // greedily place the first ball 
        int prev = A[0];  // update prev pointer as the ball is being placed here
        for(int i = 1 ; i < A.size() ; i++){
            if(A[i]-prev >= mid){  // if gap is sufficient enough place the ball
                prev = A[i];//update prev pointer 
                initial+=1;  // increment the no of placable balls
                if(initial == m ) return true;  // all balls placed return true
            }
        }
        if(initial < m) return false; // some balls are left to be placed return false
        return true;
    }
    int maxDistance(vector<int>& A, int m) {
        sort(A.begin()  , A.end());
        int s = 0 ,n = A.size(),  e = A[n-1];
        int ans ;
        while(s <= e){
            int mid = s + (e-s)/2;
            
            if(isAnswer(A, mid ,m)){
                ans = mid , s = mid+1; // if this gap is sufficient enough try widening the gap
                
            }else{
                e = mid-1; // reduce the gap size 
            }
        }
        return ans;
    }
};