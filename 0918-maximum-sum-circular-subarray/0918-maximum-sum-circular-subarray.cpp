class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size() == 0) return 0; // Edge case if the array is empty
        int sum = A[0]; // variable to store the total sum of the array
        int maxSoFar = A[0]; // variable to store the maximum sum of subarrays ending at the current position
        int maxTotal = A[0]; // variable to store the overall maximum sum of subarrays
        int minSoFar = A[0]; // variable to store the minimum sum of subarrays ending at the current position
        int minTotal = A[0]; // variable to store the overall minimum sum of subarrays
        for(int i = 1; i< A.size();i++){
            maxSoFar = max(A[i], maxSoFar + A[i]); // update maxSoFar
            maxTotal = max(maxTotal, maxSoFar); // update maxTotal
            
            minSoFar = min(A[i], minSoFar + A[i]); // update minSoFar
            minTotal = min(minTotal, minSoFar); // update minTotal
            sum += A[i]; // update the total sum of the array

        }
        if(sum == minTotal) return maxTotal; // if all elements in the array are negative
        return max(sum - minTotal, maxTotal); // return the maximum circular subarray sum
    }
};