class Solution {
public:
    /* =========================================================
     * ALGORITHM INTUITION & APPROACH: BUBBLE SORT (Optimized)
     * =========================================================
     * 1. Iteration: Repeatedly step through the list, compare adjacent 
     *    elements, and swap them if they are in the wrong order.
     * 2. Optimization (Early Exit): A `swapped` boolean flag tracks whether 
     *    any swaps occurred during the current pass. If no swaps happen, 
     *    the array is already sorted, allowing us to break early.
     * 
     * TIME COMPLEXITY:
     * - Best Case: O(N) when the array is already sorted (due to early exit).
     * - Average and Worst Case: O(N^2) for randomly ordered or reverse-sorted arrays.
     * 
     * SPACE COMPLEXITY:
     * - Auxiliary Space: O(1) as sorting is performed in-place.
     * ========================================================= */

    void sort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            bool swapped = false; 
            for (int j = 0; j < n - i; j++) {
                if (arr[j + 1] < arr[j]) {
                    swap(arr[j + 1], arr[j]);
                    swapped = true;
                }
            }
            if (swapped == false) {
                break;
            }
        }
    }

    void sortColors(vector<int>& nums) {
        sort(nums);
    }
};
