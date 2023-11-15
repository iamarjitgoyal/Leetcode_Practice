class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());

        // Step 2: Ensure the first element is 1
        arr[0] = 1;

        // Step 3: Iterate through the array to satisfy the absolute difference condition
        for (int i = 1; i < arr.size(); ++i) {
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }

        // Step 4: The maximum element in the modified array is the result
        return arr.back();
    }
};
